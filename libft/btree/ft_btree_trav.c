/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_trav.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:13:41 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 02:56:25 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

size_t	ft_btree_trav(const t_btree *bt, t_fn1 fn, int reverse)
{
	size_t	i;

	i = 0;
	if (!reverse)
	{
		bt = ft_btree_least(bt);
		while (bt)
		{
			(*fn)((void *) bt);
			bt = ft_btree_next(bt);
			++i;
		}
	}
	else
	{
		bt = ft_btree_most(bt);
		while (bt)
		{
			(*fn)((void *) bt);
			bt = ft_btree_prev(bt);
			++i;
		}
	}
	return (i);
}

size_t	ft_btree_trav2(const t_btree *bt, t_fn2 fn, void *udata, int reverse)
{
	size_t	i;

	i = 0;
	if (!reverse)
	{
		bt = ft_btree_least(bt);
		while (bt)
		{
			(*fn)((void *) bt, udata);
			bt = ft_btree_next(bt);
			++i;
		}
	}
	else
	{
		bt = ft_btree_most(bt);
		while (bt)
		{
			(*fn)((void *) bt, udata);
			bt = ft_btree_prev(bt);
			++i;
		}
	}
	return (i);
}
