/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 17:57:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	returned string must be ft_free'd

static char	*_get_abspath(const char *cmd)
{
	char	*path;
	char	**dirs;

	if (g_shell->_path)
		dirs = g_shell->_path;
	else
	{
		path = ft_env_var("PATH", g_shell->env.data);
		if (!path)
			return (0);
		dirs = ft_split(path, ':');
		if (!dirs)
		{
			enomem();
			return (0);
		}
		g_shell->_path = dirs;
	}
	return (ft_abspath_of_cmd(cmd, dirs));
}

/*
 *	1) try open/read files
 *	2) try get absolute path
 *	3) fork
 */

int	exec_cmd(t_cmdgrp *cgrp, t_cmd *cmd, size_t num)
{
	char	**args;
	char	*abspath;

	args = (char **) cmd->args.data;
	abspath = 0;
	if (!cmd_redir(cmd))
		return (0);
	if (!cmd_builtin(args[0]))
	{
		abspath = _get_abspath(args[0]);
		if (!abspath)
			ft_dprintf(2, "%s: command not found\n", args[0]);
	}
	cmd->_pid = fork();
	if (cmd->_pid == 0)
	{
		_treat_pipes(cgrp, cmd, num);
		if (cmd_builtin(args[0]))
			exit(exec_builtin(cgrp, cmd));
		execve(abspath, args, (char **) g_shell->env.data);
		exit(127);
	}
	if (abspath)
		ft_free(abspath);
	return (1);
}
