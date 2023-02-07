/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 05:16:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_builtin
{
	char	*str;
	int		(*f)(t_cmdline *, t_cmd *, t_shell *);
}	t_builtin;

int	exec_builtin(t_cmdline *cl, t_cmd *cmd, t_shell *sh)
{
	char					*s;
	t_builtin				*p;
	static const t_builtin	builtins[] = {
		{"echo", &builtin_echo},
		{"cd", &builtin_cd},
		{"pwd", &builtin_pwd},
		{"export", &builtin_export},
		{"unset", &builtin_unset},
		{"env", &builtin_env},
		{"exit", &builtin_exit},
		{0}
	};

	s = *(char **) ft_arr_get(&cmd->args, 0);
	p = (t_builtin *) &builtins[0];
	while (p->str)
	{
		if (!ft_strcmp(s, p->str))
			return ((*p->f)(cl, cmd, sh));
	}
	return (0);
}
