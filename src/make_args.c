/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 14:55:00 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arr	*make_args(t_arr *args)
{
	return ((t_arr *) args);
}

/*

t_arr new_string;
char c;

ft_arr_init(&new_string, 1, sizeof(char));
ft_arr_append(&new_string, &c, 0);

char *s = new_string.data;

*/