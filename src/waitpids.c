/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:28:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 19:14:14 by pmarquis         ###   lausanne.ch       */
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
	}
}

//	returned value is ignored

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
			error(0, "waitpid");
		if (WIFEXITED(stat))
			res = WEXITSTATUS(stat);
		else
			res = 1;
	}
	g_shell->retval = res;
	return (res);
}
