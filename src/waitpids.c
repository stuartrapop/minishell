/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:28:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 00:39:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_close_all(const t_arr *cmds)
{
	size_t	i;
	t_cmd	*cmd;

	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		fd_close(&cmd->_pipe[0]);
		fd_close(&cmd->_pipe[1]);
		if (cmd->_input_or_heredoc == redir_input)
			fd_close(&cmd->_input_fd);
		else if (cmd->_input_or_heredoc == redir_heredoc)
			fd_close(&cmd->_heredoc_fd);
		if (cmd->_output_or_append == redir_output)
			fd_close(&cmd->_output_fd);
		else if (cmd->_output_or_append == redir_append)
			fd_close(&cmd->_append_fd);
	}
}

//	returned value is ignored
//	waitpid error is ignored (ctrl-c interrupt)

int	waitpids(const t_arr *cmds)
{
	size_t	i;
	t_cmd	*cmd;
	int		stat;
	int		res;

	_close_all(cmds);
	res = 1;
	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		if (waitpid(cmd->_pid, &stat, 0) == -1)
			res = 0;
		else if (WIFEXITED(stat))
			res = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
			res = WTERMSIG(stat);
		else
			res = 0;
		cmd->_pid = -1;
	}
	g_shell->retval = res;
	g_shell->cmdgrp = 0;
	return (res);
}
