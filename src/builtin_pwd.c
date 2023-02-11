/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 20:02:49 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAXPATH	4096

int	builtin_pwd(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	path[MAXPATH];
	char	*p;

	(void) cgrp;
	(void) cmd;
	p = getcwd(path, MAXPATH);
	if (!p)
		return (1 + error("getcwd", strerror(errno)));
	if (ft_printf("%s\n", path) != (int) ft_strlen(path) + 1)
		return (1 + error("write", strerror(errno)));
	return (0);
}
