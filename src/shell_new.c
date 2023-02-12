/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:16:25 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 04:00:13 by pmarquis         ###   lausanne.ch       */
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
		if (!s || !ft_arr_append(env, &s, 0))
			return (0);
		++i;
	}
	return (1);
}

static int	_env_dup(t_arr *env, char *environ[])
{
	if (!ft_arr_init(env, _count(environ), sizeof(char *))
		|| !_copy(env, environ))
		return (0);
	return (1);
}

static int	_shell_init(t_shell *sh, char *environ[])
{
	if (!_env_dup(&sh->env, environ))
		return (0);
	return (1);
}

t_shell	*shell_new(char *environ[])
{
	t_shell	*sh;

	sh = ft_calloc(1, sizeof(t_shell));
	if (!sh || !_shell_init(sh, environ))
		enomem();
	return (sh);
}
