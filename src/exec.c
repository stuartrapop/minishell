/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 01:07:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_exec(t_node *nd, t_shell *sh);

static void	_exec_cmd(t_node *nd, t_shell *sh)
{
	size_t		i;
	t_cmdline	*cl;
	t_cmd		*cmd;

	assert(nd->tp == nd_cmd);
	cl = nd->cmdline;
	i = -1;
	while (++i < cl->cmds.nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(&cl->cmds, i);
		assert(cmd);
		if (!exec_cmd(cl, cmd, sh))
			break ;
	}
}

static void	_exec_and(t_node *nd, t_shell *sh)
{
	assert(nd->tp == nd_and);
	_exec(nd->left, sh);
	if (sh->retval == 0)
		_exec(nd->right, sh);
}

static void	_exec_or(t_node *nd, t_shell *sh)
{
	assert(nd->tp == nd_or);
	_exec(nd->left, sh);
	if (sh->retval != 0)
		_exec(nd->right, sh);
}

static void	_exec(t_node *nd, t_shell *sh)
{
	if (nd->tp == nd_cmd)
		_exec_cmd(nd, sh);
	else if (nd->tp == nd_and)
		_exec_and(nd, sh);
	else if (nd->tp == nd_or)
		_exec_or(nd, sh);
	else
	{
		printf("nd->tp = %d\n", nd->tp);
		assert(0);
	}
}

void	exec(t_node *root, char *environ[])
{
	static t_shell	*sh;

	if (!sh)
	{
		sh = shell_new(environ);
		if (!sh)
		{
			error(0, "nomem");
			return ;
		}
	}
	_exec(root, sh);
}
