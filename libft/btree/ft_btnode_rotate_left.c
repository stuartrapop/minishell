/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_rotate_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:43:35 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btnode_rotate_left(t_btree *x, t_btree *z)
{
	t_btree	*t23;

	t23 = z->less;
	x->more = t23;
	if (t23)
		t23->parent = x;
	z->less = x;
	x->parent = z;
	if (z->bfactor == 0)
	{
		x->bfactor = 1;
		z->bfactor = -1;
	}
	else
	{
		x->bfactor = 0;
		z->bfactor = 0;
	}
	return (z);
}
