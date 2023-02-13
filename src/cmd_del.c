/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:52:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 01:22:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	_fd_close(int fd)
{
	if (fd != -1)
		close(fd);
}

static void	_cmd_fini(t_cmd *cmd)
{
	ft_arr_fini(&cmd->args, &ft_del);
	ft_arr_fini(&cmd->redirs, &redir_del);
	_fd_close(cmd->_pipe[0]);
	_fd_close(cmd->_pipe[1]);
	_fd_close(cmd->_heredoc_fd);
	_fd_close(cmd->_input_fd);
	_fd_close(cmd->_output_fd);
	_fd_close(cmd->_append_fd);
}

void	cmd_del(void *command)
{
	t_cmd	**cmd;

	cmd = command;
	assert(*cmd);
	_cmd_fini(*cmd);
	ft_free(*cmd);
	*cmd = 0;
}
