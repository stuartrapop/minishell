/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 00:40:04 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exec(t_cmdgrp *cgrp, t_cmd *cmd)
{
	const char	**noargs = {0};
	char		**p;

	(void) cgrp;
	p = ft_arr_get(&cmd->args, 1);
	if (!p)
		return (1);
	if (cmd->args.nelem > 2)
		execve(*p, &((char *const *) cmd->args.data)[1],
			(char *const *) g_shell->env.data);
	else
		execve(*p, (char *const *) noargs, g_shell->env.data);
	return (1 + error("exec", strerror(errno)));
}
