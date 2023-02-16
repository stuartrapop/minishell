/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:28:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 14:46:49 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_close_all_fildes(const t_arr *cmds)
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

//	signal interrupts cause waitpid to fail, in that case, retry

static int	_waitfor(int pid)
{
	int	stat;

	while (waitpid(pid, &stat, WUNTRACED) == -1)
	{
		/* if (waitpid(pid, &stat, WUNTRACED) == -1) */
		/* 	return (1); */
	}
	if (WIFSTOPPED(stat))
		return (WSTOPSIG(stat));
	if (WIFSIGNALED(stat))
		return (WTERMSIG(stat));
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	assert(0);
	return (0);
}

//	returned value is ignored

int	waitpids(const t_arr *cmds)
{
	size_t	i;
	t_cmd	*cmd;
	int		res;

	_close_all_fildes(cmds);
	res = 1;
	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		if (cmd->_pid == -1)
			continue ;
		res = _waitfor(cmd->_pid);
		cmd->_pid = -1;
	}
	termios_bs(0);
	g_shell->retval = res;
	g_shell->_cmdgrp = 0;
	return (res);
}
