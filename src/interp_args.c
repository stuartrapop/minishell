/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:27:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 00:19:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	for debugging purposes...

int	interp_args(int argc, char *argv[])
{
	int	i;

	i = -1;
	while (++i < argc)
		interp(argv[i]);
	ft_memtrash();
	return (g_shell->retval);
}
