/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_rotate_rightleft.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:17:31 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void	_ft_btnode_rotate_rightleft(t_btree *x, t_btree *z, t_btree *y)
{
	if (y->bfactor > 0)
	{
		x->bfactor = -1;
		z->bfactor = 0;
	}
	else if (y->bfactor == 0)
	{
		x->bfactor = 0;
		z->bfactor = 0;
	}
	else
	{
		x->bfactor = 0;
		z->bfactor = 1;
	}
	y->bfactor = 0;
}

t_btree	*ft_btnode_rotate_rightleft(t_btree *x, t_btree *z)
{
	t_btree	*y;
	t_btree	*t2;
	t_btree	*t3;

	y = z->less;
	t3 = y->more;
	z->less = t3;
	if (t3)
		t3->parent = z;
	y->more = z;
	z->parent = y;
	t2 = y->less;
	x->more = t2;
	if (t2)
		t2->parent = x;
	y->less = x;
	x->parent = y;
	_ft_btnode_rotate_rightleft(x, z, y);
	return (y);
}
