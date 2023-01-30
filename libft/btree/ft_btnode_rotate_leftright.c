/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_rotate_leftright.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:45:24 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void	_ft_btnode_rotate_leftright(t_btree *x, t_btree *z, t_btree *y)
{
	if (y->bfactor > 0)
	{
		x->bfactor = 0;
		z->bfactor = -1;
	}
	else if (y->bfactor == 0)
	{
		x->bfactor = 0;
		z->bfactor = 0;
	}
	else
	{
		x->bfactor = 1;
		z->bfactor = 0;
	}
	y->bfactor = 0;
}

t_btree	*ft_btnode_rotate_leftright(t_btree *x, t_btree *z)
{
	t_btree	*y;
	t_btree	*t2;
	t_btree	*t3;

	y = z->more;
	t3 = y->less;
	z->more = t3;
	if (t3)
		t3->parent = z;
	y->less = z;
	z->parent = y;
	t2 = y->more;
	x->less = t2;
	if (t2)
		t2->parent = x;
	y->more = x;
	x->parent = y;
	_ft_btnode_rotate_leftright(x, z, y);
	return (y);
}
