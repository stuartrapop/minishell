/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 05:01:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	hints:

	put in t_shell* what must survive between each user-input
	put in t_cmdline* what must survive between each 'cmd' (pipes etc)

	for cmds:

	char **args = &((char **) cmd->args.data)[1]
	char **env = (char **) sh->env.data
 */

int	exec_cmd(t_cmdline *cl, t_cmd *cmd, t_shell *sh)
{
	size_t	i;
	char	*s;

	s = *(char **) ft_arr_get(&cmd->args, 0);
	assert(s);
	if (cmd_builtin(s))
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
