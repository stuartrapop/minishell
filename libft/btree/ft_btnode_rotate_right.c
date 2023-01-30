/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_rotate_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:17:53 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btnode_rotate_right(t_btree *x, t_btree *z)
{
	t_btree	*t23;

	t23 = z->more;
	x->less = t23;
	if (t23)
		t23->parent = x;
	z->more = x;
	x->parent = z;
	if (z->bfactor == 0)
	{
		x->bfactor = -1;
		z->bfactor = 1;
	}
	else
	{
		x->bfactor = 0;
		z->bfactor = 0;
	}
	return (z);
}
