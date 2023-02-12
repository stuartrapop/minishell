/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 19:29:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_builtin
{
	char	*str;
	int		(*f)(t_cmdgrp *, t_cmd *);
}	t_builtin;

//	return exit status of builtin command

int	exec_builtin(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char					*s;
	t_builtin				*p;
	static const t_builtin	builtins[] = {
		{"cd", &builtin_cd},
		{"echo", &builtin_echo},
		{"env", &builtin_env},
		{"exit", &builtin_exit},
		{"export", &builtin_export},
		{"pwd", &builtin_pwd},
		{"unset", &builtin_unset},
		{0}
	};

	s = unbs(*(char **) ft_arr_get(&cmd->args, 0));
	p = (t_builtin *) &builtins[0];
	while (p->str)
	{
		if (*p->str == *s && !ft_strcmp(p->str, s))
			return ((*p->f)(cgrp, cmd));
		++p;
	}
	assert(0);
	return (1);
}

static int	_clone(int *stdin_clone, int *stdout_clone)
{
	*stdin_clone = dup(0);
	*stdout_clone = dup(1);
	if (*stdin_clone == -1 || *stdout_clone == -1)
		return (error("dup", strerror(errno)));
	return (1);
}

static void	_restore(int stdin_clone, int stdout_clone)
{
	if (dup2(stdin_clone, 0) == -1 || dup2(stdout_clone, 1) == -1)
		error("dup2", strerror(errno));
}

//	return exit status of the builtin command

int	exec_simple_builtin(t_cmdgrp *cgrp, t_cmd *cmd)
{
	int	stdin_clone;
	int	stdout_clone;
	int	i;

	if (!_clone(&stdin_clone, &stdout_clone))
		return (1);
	if (!cmd_redir(cmd))
	{
		_restore(stdin_clone, stdout_clone);
		return (1);
	}
	i = exec_builtin(cgrp, cmd);
	_restore(stdin_clone, stdout_clone);
	return (i);
}
