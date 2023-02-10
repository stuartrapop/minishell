/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 16:02:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_builtin
{
	char	*str;
	int		(*f)(t_cmdgrp *, t_cmd *);
}	t_builtin;

//	return exit status of builtin command

int	exec_builtin(t_cmdgrp *cl, t_cmd *cmd)
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

	s = *(char **) ft_arr_get(&cmd->args, 0);
	p = (t_builtin *) &builtins[0];
	while (p->str)
	{
		if (*p->str == *s && !ft_strcmp(p->str, s))
			return ((*p->f)(cl, cmd));
		++p;
	}
	assert(0);
	return (127);
}
