/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:43:26 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 19:38:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_env_set(t_arr *env, const char *name, const char *value)
{
	char	*s;

	s = ft_strdup(name);
	if (!s)
		return (error(0, "nomem"));
	if (!ft_append(&s, "=") || !ft_append(&s, value)
		|| !ft_arr_append(env, &s, 0))
	{
		ft_free(s);
		return (error(0, "nomem"));
	}
	return (1);
}

int	env_set(t_arr *env, const char *varname, const char *value)
{
	size_t	i;

	i = env_indexof(env, varname);
	if (i == (size_t) -1)
		return (_env_set(env, varname, value));
	if (!ft_arr_unset(env, i, &ft_del))
		assert(0);
	return (_env_set(env, varname, value));
}
