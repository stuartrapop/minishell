/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:06:16 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 15:22:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_init(t_cmd *cmd)
{
	cmd->_input_fd = -1;
	cmd->_heredoc_fd = -1;
	cmd->_output_fd = -1;
	cmd->_append_fd = -1;
	ft_memset(&cmd->_io, -1, sizeof(int) * 2);
	if (!ft_arr_init(&cmd->args, 1, sizeof(char *))
		|| !ft_arr_init(&cmd->redirs, 0, sizeof(t_redir)))
		return (0);
	return (1);
}

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (0);
	if (!cmd_init(cmd))
	{
		ft_free(cmd);
		return (0);
	}
	return (cmd);
}
