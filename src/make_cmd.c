/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:38:46 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 18:25:30 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_emptycmd(void)
{
	char	*s;

	if (!ft_strdup2("", &s))
		enomem();
	return (s);
}

//	unroll all args into one string, possibly empty
//	returned string must be freed

char	*make_cmd(t_arr *args)
{
	t_arr	new_string;
	size_t	i;
	char	*full_command;
	char	*s;

	if (args->nelem == 0)
		return (_emptycmd());
	if (!ft_arr_init(&new_string, 128, sizeof(char)))
		enomem();
	i = -1;
	while (++i < args->nelem)
	{
		s = *(char **) ft_arr_get(args, i);
		add_arg_to_full_command(&new_string, s);
		if (i != args->nelem - 1 && !ft_arr_append(&new_string, " ", 0))
			enomem();
	}
	if (!ft_strdup2(new_string.data, &full_command))
		enomem();
	ft_arr_fini(&new_string, 0);
	return (full_command);
}
