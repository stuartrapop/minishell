/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:59:14 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 04:59:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_builtin(const char *cmd)
{
	char				**s;
	static const char	*builtins[] = {"echo", "cd", "pwd", "export", "unset",
		"env", "exit", 0};

	s = (char **) &builtins[0];
	while (*s)
	{
		if (!ft_strcmp(*s, cmd))
			return (1);
		++s;
	}
	return (0);
}
