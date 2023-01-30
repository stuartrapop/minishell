/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_removed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:12:36 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/19 02:14:29 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	_ft_btnode_rem_1(t_btree *x, t_btree **z, t_btree **n, int *b)
{
	if (x->bfactor > 0)
	{
		*z = x->more;
		*b = (*z)->bfactor;
		if (*b < 0)
			*n = ft_btnode_rotate_rightleft(x, *z);
		else
			*n = ft_btnode_rotate_left(x, *z);
	}
	else
	{
		if (x->bfactor == 0)
		{
			x->bfactor = 1;
			return (1);
		}
		*n = x;
		(*n)->bfactor = 0;
		return (2);
	}
	return (0);
}

static int	_ft_btnode_rem_2(t_btree *x, t_btree **z, t_btree **n, int *b)
{
	if (x->bfactor < 0)
	{
		*z = x->less;
		*b = (*z)->bfactor;
		if (*b > 0)
			*n = ft_btnode_rotate_leftright(x, *z);
		else
			*n = ft_btnode_rotate_right(x, *z);
	}
	else
	{
		if (x->bfactor == 0)
		{
			x->bfactor = -1;
			return (1);
		}
		*n = x;
		(*n)->bfactor = 0;
		return (2);
	}
	return (0);
}

static int	_ft_btnode_rem_3(t_btree *n, t_btree *g, t_btree **x, int b)
{
	n->parent = g;
	if (g)
	{
		if (*x == g->less)
			g->less = n;
		else
			g->more = n;
		if (b == 0)
			return (1);
	}
	*x = g;
	return (0);
}

static void	_ft_btnode_removed(t_btree *n, t_btree *x, int chld, int *i)
{
	t_btree	*z;
	t_btree	*g;

	while (x)
	{
		g = x->parent;
		if ((n && n == x->less) || (!n && chld < 0))
			*i = _ft_btnode_rem_1(x, &z, &n, &i[1]);
		else
			*i = _ft_btnode_rem_2(x, &z, &n, &i[1]);
		if (*i == 1)
			break ;
		else if (*i == 2)
		{
			x = g;
			continue ;
		}
		if (_ft_btnode_rem_3(n, g, &x, i[1]) == 1)
			break ;
	}
}

void	ft_btnode_removed(t_btree *n, t_btree *x, int fromchild)
{
	int	i[2];

	if (n)
		x = n->parent;
	_ft_btnode_removed(n, x, fromchild, i);
}
