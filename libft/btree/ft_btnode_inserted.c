/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_inserted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:39:46 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 22:40:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

// z == x->more
static int	_ft_btnode_ins_1(t_btree **z, t_btree **x, t_btree **g, t_btree **n)
{
	if ((*x)->bfactor > 0)
	{
		*g = (*x)->parent;
		if ((*z)->bfactor < 0)
			*n = ft_btnode_rotate_rightleft(*x, *z);
		else
			*n = ft_btnode_rotate_left(*x, *z);
	}
	else
	{
		if ((*x)->bfactor < 0)
		{
			(*x)->bfactor = 0;
			return (1);
		}
		(*x)->bfactor = 1;
		*z = *x;
		*x = (*z)->parent;
		return (2);
	}
	return (0);
}

// z == x->less
static int	_ft_btnode_ins_2(t_btree **z, t_btree **x, t_btree **g, t_btree **n)
{
	if ((*x)->bfactor < 0)
	{
		*g = (*x)->parent;
		if ((*z)->bfactor > 0)
			*n = ft_btnode_rotate_leftright(*x, *z);
		else
			*n = ft_btnode_rotate_right(*x, *z);
	}
	else
	{
		if ((*x)->bfactor > 0)
		{
			(*x)->bfactor = 0;
			return (1);
		}
		(*x)->bfactor = -1;
		*z = *x;
		*x = (*z)->parent;
		return (2);
	}
	return (0);
}

static void	_ft_btnode_ins_3(t_btree *n, t_btree *g, t_btree *x)
{
	n->parent = g;
	if (g)
	{
		if (x == g->less)
			g->less = n;
		else
			g->more = n;
	}
}

static void	_ft_btnode_inserted(t_btree *z, t_btree *x)
{
	int		i;
	t_btree	*g;
	t_btree	*n;

	while (x)
	{
		if (z == x->more)
		{
			i = _ft_btnode_ins_1(&z, &x, &g, &n);
			if (i == 1)
				break ;
			else if (i == 2)
				continue ;
		}
		else
		{
			i = _ft_btnode_ins_2(&z, &x, &g, &n);
			if (i == 1)
				break ;
			else if (i == 2)
				continue ;
		}
		_ft_btnode_ins_3(n, g, x);
		break ;
	}
}

void	ft_btnode_inserted(t_btree *z)
{
	_ft_btnode_inserted(z, z->parent);
}
