/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 01:47:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_builtin(const char *cmd)
{
	static const char	*builtins[] = {
		"export",
		0
	};
	char				**s;

	s = (char **) &builtins[0];
	while (*s)
	{
		if (!ft_strcmp(*s, cmd))
			return (1);
		++s;
	}
	return (0);
}

/*
	hint:

	args = &((char **) cmd->args.data)[1]
 */

int	exec_cmd(t_cmdline *cl, t_cmd *cmd, t_shell *sh)
{
	size_t	i;
	char	*s;

	s = *(char **) ft_arr_get(&cmd->args, 0);
	assert(s);
	if (_is_builtin(s))
		return (exec_builtin(cl, cmd, sh));
	i = -1;
	while (++i < cmd->args.nelem)
	{
		s = *(char **) ft_arr_get(&cmd->args, i);
		assert(s);
		printf("%zu:'%s' ", i, s);
	}
	printf("%s", "\n");
	return (1);
}
