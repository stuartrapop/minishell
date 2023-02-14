/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 14:58:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	expand all vars and wildcards

t_arr	*make_args(t_arr *args)
{
	size_t	i;
	char	*s;

	i = 0;
	while (++i < args->nelem)
	{
		s = *(char **) ft_arr_get(args, i);
		if (*s == '*' && !ft_strcmp(s, "*"))
		{
			if (!wildcard(args, i))
				return (0);
			i = -1;
		}
	}
	return (args);
}

/*

t_arr new_string;
char c;

ft_arr_init(&new_string, 1, sizeof(char));
ft_arr_append(&new_string, &c, 0);

char *s = new_string.data;

*/
