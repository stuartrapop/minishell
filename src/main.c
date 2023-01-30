/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:47:25 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/18 18:12:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_add_history(const char *s)
{
	char		*arg;
	static char	*prev;

	arg = ft_strip(s);
	if (!arg)
	{
		error("ft_strip", "nomem");
		return ;
	}
	if (prev)
	{
		if (*arg != *prev || ft_strcmp(arg, prev))
			add_history(arg);
		ft_free(prev);
		prev = 0;
	}
	else
		add_history(arg);
	prev = arg;
}

static char	*_readline(void)
{
	char	*s;
	char	*ret;

	while (1)
	{
		s = readline(PS1);
		if (s)
		{
			if (ft_strisspace(s))
			{
				free(s);
				continue ;
			}
			_add_history(s);
			ret = ft_strdup(s);
			if (!ret)
				error("ft_strdup", "nomem");
			free(s);
			return (ret);
		}
		return (0);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	char	*s;

	install_sighandler();
	while (1)
	{
		s = _readline();
		if (s)
		{
			interp(s, env);
			ft_free(s);
			continue ;
		}
		break ;
	}
	ft_memtrash();
	rl_clear_history();
	return (0);
}
