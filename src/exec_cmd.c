/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 14:54:55 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_get_abspath(const char *cmd)
{
	char	*path;
	char	**dirs;
	char	*res;

	path = ft_env_var("PATH", g_shell->env.data);
	if (!path)
		return (0);
	dirs = ft_split(path, ':');
	if (!dirs)
		enomem();
	res = ft_abspath_of_cmd(cmd, dirs);
	ft_del_arr(&dirs);
	return (res);
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

/*
 *	1) open all fildes
 *	2) if ok, make arg0, possible switch to builtin
 *	3) check arg0
 *	4) if ok, make args
 *	returned value is ignored
 */

int	exec_cmd(t_cmdgrp *cgrp, t_cmd *cmd, size_t num)
{
	char	*arg0;
	char	*abspath;

	abspath = 0;
	cmd->_pid = fork();
	if (cmd->_pid == 0)
	{
		if (!cmd_fildes(cgrp, cmd, num))
			exit(1);
		arg0 = make_arg0(cmd);
		if (cmd_builtin(arg0))
			exit(exec_builtin(cgrp, cmd));
		_treat_arg0(arg0, &abspath);
		if (abspath && !make_args(&cmd->args))
			ft_del(&abspath);
		execve(abspath, cmd->args.data, g_shell->env.data);
		exit(1);
	}
	return (1);
}
