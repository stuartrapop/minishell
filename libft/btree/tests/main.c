/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:39 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/19 20:21:28 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "ft_btree.h"

#ifdef NDEBUG
# include "../ft_btnode_debug.c"
#endif

int	main(int argc, char *argv[])
{
	int		i;
	int		x;
	t_btree	*bt;

	bt = 0;
	i = 1;
	while (i < argc)
	{
		if (*ft_atoi(argv[i], &x))
			return (1);
		if (ft_btree_ins(&bt, (size_t)x, 0) < 0)
			return (1);
		++i;
	}
	ft_btree_trav(bt, (t_fn1)ft_btnode_debug);
	i = 1;
	while (i < argc)
	{
		if (*ft_atoi(argv[i], &x))
			return (1);
		ft_btree_rem(&bt, (size_t)x, 0);
		++i;
	}
	if (bt)
		return (1);
	return (0);
}
