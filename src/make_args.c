/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 21:31:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arr	*make_args(const t_arr *args)
{
	size_t	i;
	char	**arg;

	i = 0;
	while (++i < args->nelem)
	{
		arg = (char **) ft_arr_get(args, i);
		if (!string(arg))
			enomem();
	}
	return ((t_arr *) args);
}
