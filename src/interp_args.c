/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:27:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 22:27:59 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	for debugging purposes...

int	interp_args(int argc, char *argv[])
{
	int		i;

	i = -1;
	while (++i < argc)
		interp(argv[i]);
	finish(g_shell->retval);
	return (0);
}
