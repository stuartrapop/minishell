/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 15:23:55 by pmarquis         ###   lausanne.ch       */
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
	char					*arg0;
	t_builtin				*p;
	static const t_builtin	builtins[] = {{"cd", &builtin_cd},
	{"echo", &builtin_echo}, {"env", &builtin_env}, {"exit", &builtin_exit},
	{"export", &builtin_export}, {"memusage", &builtin_memusage},
	{"pwd", &builtin_pwd}, {"unset", &builtin_unset}, {0}};

	assert(cmd->_arg0_made);
	if (!make_args(&cmd->args))
		return (1);
	arg0 = *(char **) ft_arr_get(&cmd->args, 0);
	p = (t_builtin *) &builtins[0];
	while (p->str)
	{
		if (*p->str == *arg0 && !ft_strcmp(p->str, arg0))
			return ((*p->f)(cgrp, cmd));
		++p;
	}
	assert(0);
	return (1);
}

static void	_clone(int *stdin_clone, int *stdout_clone)
{
	*stdin_clone = dup(0);
	*stdout_clone = dup(1);
	if (*stdin_clone == -1 || *stdout_clone == -1)
		fatal("dup", strerror(errno));
}

static void	_restore(int stdin_clone, int stdout_clone)
{
	if (dup2(stdin_clone, 0) == -1 || dup2(stdout_clone, 1) == -1)
		fatal("dup2", strerror(errno));
}

//	return exit status of the builtin command

int	exec_simple_builtin(t_cmdgrp *cgrp, t_cmd *cmd)
{
	int	stdin_clone;
	int	stdout_clone;
	int	i;

	_clone(&stdin_clone, &stdout_clone);
	if (!cmd_redir(cmd))
	{
		_restore(stdin_clone, stdout_clone);
		return (1);
	}
	i = exec_builtin(cgrp, cmd);
	_restore(stdin_clone, stdout_clone);
	return (i);
}
