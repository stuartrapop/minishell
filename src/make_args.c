/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 16:45:34 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	expand_arg_wildcards(t_arr *args)
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
	return (1);
}

char	*make_full_command(t_arr *args)
{
	t_arr		new_string;
	size_t		i;
	char		*full_command;

	ft_arr_init(&new_string, 128, sizeof(char));
	i = 0;
	while (i < args->nelem)
	{
		if (!((char **)args->data)[i])
			break ;
		add_arg_to_full_command(&new_string, ((char **)args->data)[i]);
		if (i != args->nelem - 1)
			ft_arr_append(&new_string, " ", 0);
		i++;
	}
	full_command = ft_strdup((char *)new_string.data);
	ft_arr_fini(&new_string, 0);
	return (full_command);
}

int	make_args(t_arr *args)
{
	char		*full_command;

	full_command = make_full_command(args);
	split_full_command(&full_command, args);
	ft_free(full_command);
	expand_arg_wildcards(args);
	return (1);
}
