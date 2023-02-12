/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:27:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 04:30:04 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interp_args(int argc, char *argv[])
{
	int	i;

	i = -1;
	while (++i < argc)
		interp(argv[i]);
	finish(0);
	return (0);
}
