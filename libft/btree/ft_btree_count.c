/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:49:49 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

size_t	ft_btree_count(const t_btree *bt)
{
	size_t	cnt;
	t_btree	*nd;

	cnt = 0;
	nd = ft_btree_least(bt);
	while (nd)
	{
		++cnt;
		nd = ft_btree_next(nd);
	}
	return (cnt);
}
