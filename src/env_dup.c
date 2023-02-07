/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:46:55 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 00:11:25 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	_count(char *env[])
{
	size_t	i;

	i = 0;
	while (env[i])
		++i;
	return (i);
}

static int	_copy(t_arr *env, char *environ[])
{
	size_t	i;
	char	*s;

	i = 0;
	while (environ[i])
	{
		s = ft_strdup(environ[i]);
		if (!s)
		{
			ft_arr_fini(env, &ft_del);
			return (0);
		}
		if (!ft_arr_append(env, &s, 0))
		{
			ft_free(s);
			ft_arr_fini(env, &ft_del);
			return (0);
		}
		++i;
	}
	return (1);
}

int	env_dup(t_arr *env, char *environ[])
{
	if (!ft_arr_init(env, _count(environ), sizeof(char *))
		|| !_copy(env, environ))
		return (0);
	return (1);
}
