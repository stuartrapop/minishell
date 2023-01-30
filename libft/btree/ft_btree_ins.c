/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:29:47 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

// ret -1 on error, 0 if key exists, 1 if ok
int	ft_btree_ins(t_btree **bt, size_t key, void *val)
{
	int	i;

	i = ft_btnode_insert(bt, key, val, 0);
	if (i > 0)
		*bt = ft_btree_root(*bt);
	return (i);
}
