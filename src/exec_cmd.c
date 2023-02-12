/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 19:25:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			enomem();
		g_shell->_path = dirs;
	}
	return (ft_abspath_of_cmd(cmd, dirs));
}

static void	_treat_arg0(const char *cmd, char **abspath)
{
	if (ft_strchr(cmd, '/'))
	{
		if (!ft_file_exists(cmd))
			ft_dprintf(2, "error: %s: no such file or directory\n", cmd);
		else if (!ft_file_executable(cmd))
			ft_dprintf(2, "error: %s: permission denied\n", cmd);
		else if (ft_file_directory(cmd))
			ft_dprintf(2, "error: %s: is a directory\n", cmd);
		else
			*abspath = (char *) cmd;
	}
	else
	{
		*abspath = _get_abspath(cmd);
		if (!*abspath)
			ft_dprintf(2, "error: %s: command not found\n", cmd);
	}
}

//	returned value is ignored

int	exec_cmd(t_cmdgrp *cgrp, t_cmd *cmd, size_t num)
{
	char	**args;
	char	*abspath;
	char	*arg0;

	g_shell->_cmdgrp = cgrp;
	args = (char **) cmd->args.data;
	abspath = 0;
	cmd->_pid = fork();
	if (cmd->_pid == 0)
	{
		if (!cmd_fildes(cgrp, cmd, num))
			exit(1);
		arg0 = unbs(args[0]);
		if (cmd_builtin(arg0))
			exit(exec_builtin(cgrp, cmd));
		_treat_arg0(arg0, &abspath);
		execve(abspath, args, (char **) g_shell->env.data);
		//ft_dprintf(2, "error: %s\n", strerror(errno));
		exit(1);
	}
	return (1);
}
