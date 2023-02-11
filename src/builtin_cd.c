/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 00:45:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	**p;
	char	*path;

	(void) cgrp;
	p = ft_arr_get(&cmd->args, 1);
	if (!p)
	{
		path = env_get(&g_shell->env, "HOME");
		if (!path)
			return (0);
	}
	else
		path = *p;
	if (chdir(path) == -1)
		return (1 + error("chdir", strerror(errno)));
	if (!env_set(&g_shell->env, "PWD", path))
		enomem();
	return (0);
}
