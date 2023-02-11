/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 17:28:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_create_pipes(t_cmdgrp *cgrp)
{
	size_t	i;
	t_cmd	*cmd;

	i = -1;
	while (++i < cgrp->cmds.nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, i);
		assert(cmd);
		if (pipe(cmd->_pipe) == -1)
			return (error("pipe", strerror(errno)));
	}
	return (1);
}

static void	_exec_cmd(t_node *nd)
{
	size_t		i;
	t_cmdgrp	*cgrp;
	t_cmd		*cmd;

	assert(nd->tp == nd_cmd);
	cgrp = nd->cmdgrp;
	cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, 0);
	if (cgrp->cmds.nelem == 1 && cmd_builtin(((char **) cmd->args.data)[0]))
	{
		g_shell->retval = exec_simple_builtin(cgrp, cmd);
		return ;
	}
	if (!_create_pipes(cgrp))
		return ;
	i = -1;
	while (++i < cgrp->cmds.nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, i);
		exec_cmd(cgrp, cmd, i);
	}
	waitpids(&cgrp->cmds);
}

static void	_exec_and(t_node *nd)
{
	assert(nd->tp == nd_and);
	exec(nd->left);
	if (g_shell->retval == 0)
		exec(nd->right);
}

static void	_exec_or(t_node *nd)
{
	assert(nd->tp == nd_or);
	exec(nd->left);
	if (g_shell->retval != 0)
		exec(nd->right);
}

void	exec(t_node *nd)
{
	if (nd->tp == nd_cmd)
		_exec_cmd(nd);
	else if (nd->tp == nd_and)
		_exec_and(nd);
	else if (nd->tp == nd_or)
		_exec_or(nd);
	else
	{
		ft_dprintf(2, "error: exec: nd->tp = %d\n", nd->tp);
		assert(0);
	}
}
