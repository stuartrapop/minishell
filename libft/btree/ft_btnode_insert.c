/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:32:41 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
 *	ret: -1 mem error
 *		 1	ok, inserted
 *		 0	key already exists, not inserted
 */
int	ft_btnode_insert(t_btree **bt, size_t key, void *val, t_btree *parent)
{
	while (1)
	{
		if (!*bt)
		{
			if (!ft_btnode_new(bt, key, val, parent))
				return (-1);
			if (parent)
				ft_btnode_inserted(*bt);
			return (1);
		}
		parent = *bt;
		if (key < (*bt)->key)
		{
			bt = &(*bt)->less;
			continue ;
		}
		else if (key > (*bt)->key)
		{
			bt = &(*bt)->more;
			continue ;
		}
		else
			return (0);
	}
}
