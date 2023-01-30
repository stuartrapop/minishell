/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:24:42 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_del(t_btree **bt, t_fn1 fn)
{
	t_btree	*next;
	t_btree	*nd;

	if (*bt)
	{
		nd = ft_btree_least(*bt);
		while (nd)
		{
			next = ft_btree_next(nd);
			ft_btnode_del(&nd, fn);
			nd = next;
		}
		*bt = 0;
	}
}
