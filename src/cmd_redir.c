/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:24:16 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/22 12:43:40 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_ambiguous(char *str)
{
	int		i;
	t_scan	scan;

	scan.within_double_quotes = 0;
	scan.within_single_quotes = 0;
	if (str[0] == '\0')
	{
		ft_dprintf(2, "error: ambiguous redirect\n");
		return (1);
	}
	i = 0;
	while (str[i])
	{
		treat_quotes(str[i], &scan);
		if (ft_strchr(" ", str[i]) && !scan.within_double_quotes && \
			!scan.within_single_quotes)
		{
			ft_dprintf(2, "error: ambiguous redirect\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	_treat_heredocs(t_cmd *cmd)
{
	size_t	i;
	t_redir	*redir;

	i = -1;
	while (++i < cmd->redirs.nelem)
	{
		redir = (t_redir *) ft_arr_get(&cmd->redirs, i);
		if (redir->tp == redir_heredoc)
		{
			// redir->str = clean_redirect(&redir->str);
			if (cmd->_heredoc_fd != -1)
				fd_close(&cmd->_heredoc_fd);
			cmd->_heredoc_fd = open_file_hd(redir->str);
			if (cmd->_heredoc_fd == -1)
				return (0);
		}
	}
	return (1);
}

static int	_treat_others(t_cmd *cmd)
{
	size_t	i;
	t_redir	*redir;

	i = -1;
	while (++i < cmd->redirs.nelem)
	{
		redir = (t_redir *) ft_arr_get(&cmd->redirs, i);
		if (is_ambiguous(redir->str))
			return (0);
		redir->str = clean_redirect(&redir->str);
		if (redir->tp == redir_input)
		{
			if (!cmd_redir_input(cmd, redir))
				return (0);
		}
		else if (redir->tp == redir_output)
		{
			if (!cmd_redir_output(cmd, redir))
				return (0);
		}
		else if (redir->tp == redir_append)
		{
			if (!cmd_redir_append(cmd, redir))
				return (0);
		}
	}
	return (1);
}

/*
 *	Treat redirections (read heredocs, open input files, open output files)
 *	Of each, the last FD opened is kept,
 *	and the FDs not used are immediately closed
 */

int	cmd_redir(t_cmd *cmd)
{
	if (!_treat_heredocs(cmd))
	{
		cmd->_status = 2;
		return (0);
	}
	if (!_treat_others(cmd))
	{
		cmd->_status = 1;
		return (0);
	}
	if (cmd->_input_or_heredoc)
	{
		assert(cmd->_input_fd != -1 || cmd->_heredoc_fd != -1);
		if (cmd->_input_or_heredoc == redir_input)
			fd_close(&cmd->_heredoc_fd);
		else
			fd_close(&cmd->_input_fd);
	}
	if (cmd->_output_or_append)
	{
		assert(cmd->_output_fd != -1 || cmd->_append_fd != -1);
		if (cmd->_output_or_append == redir_output)
			fd_close(&cmd->_append_fd);
		else
			fd_close(&cmd->_output_fd);
	}
	return (1);
}
