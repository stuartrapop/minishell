/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 02:32:21 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exec(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	**p;
	char	*abspath;

	(void) cgrp;
	p = ft_arr_get(&cmd->args, 1);
	if (!p || !*p)
		return (0);
	if (!ft_strchr(*p, '/'))
	{
		abspath = abspath_find(*p);
		if (!abspath)
			abspath = *p;
	}
	else
		abspath = *p;
	execve(abspath, &((char *const *) cmd->args.data)[1],
		(char *const *) g_shell->env.data);
	return (1 + error(*p, strerror(errno)));
}
