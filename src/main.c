/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:47:25 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 03:33:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*g_shell;

static void	_add_history(const char *s)
{
	char		*arg;
	static char	*prev;

	arg = ft_strip(s);
	if (!arg)
		enomem();
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
		s = readline(ps1());
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
				enomem();
			free(s);
			return (ret);
		}
		return (0);
	}
}

static int	_finish(int i)
{
	ft_memtrash();
	rl_clear_history();
	return (i);
}

static int	_init(int argc, char *argv[], char *env[])
{
	(void) argc;
	(void) argv;
	g_shell = shell_new(env);
	if (!g_shell)
		return (enomem());
	if (!sighandlers_install())
		return (0);
	return (1);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*s;

	if (!_init(argc, argv, env))
		return (_finish(1));
	while (1)
	{
		s = _readline();
		if (s)
		{
			interp(s);
			ft_free(s);
			continue ;
		}
		break ;
	}
	return (_finish(0));
}
