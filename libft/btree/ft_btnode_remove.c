/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:54:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btnode_remove.h"

static void	_ft_btnode_remove_000(t_btree **bt, t_params *p)
{
	p->nd = ft_btree_next(*bt);
	if (p->nd->more)
	{
		p->subtree = p->nd->more;
		p->nd->bfactor = (*bt)->bfactor;
	}
	else if (p->nd->parent != *bt)
	{
		p->fromchild = -1;
		p->parent = p->nd->parent;
		p->nd->bfactor = (*bt)->bfactor;
	}
	else
	{
		p->fromchild = 1;
		p->parent = p->nd;
	}
}

static void	_ft_btnode_remove_00(t_btree **bt, t_params *p)
{
	p->nd = ft_btree_prev(*bt);
	if (p->nd->less)
	{
		p->subtree = p->nd->less;
		p->nd->bfactor = (*bt)->bfactor;
	}
	else if (p->nd->parent != *bt)
	{
		p->fromchild = 1;
		p->parent = p->nd->parent;
		p->nd->bfactor = (*bt)->bfactor;
	}
	else
	{
		p->fromchild = -1;
		p->parent = p->nd;
	}
}

static void	_ft_btnode_remove_0(t_btree **bt, t_params *p)
{
	if ((*bt)->bfactor <= 0)
	{
		_ft_btnode_remove_00(bt, p);
	}
	else
	{
		_ft_btnode_remove_000(bt, p);
	}
	ft_btnode_replace(*bt, p->nd);
}

static void	_ft_btnode_remove_1(t_btree **bt, t_fn1 fn, t_params *p)
{
	if (fn)
		(*fn)((*bt)->val);
	if ((*bt)->less && (*bt)->more)
	{
		_ft_btnode_remove_0(bt, p);
	}
	else if ((*bt)->less)
	{
		p->subtree = (*bt)->less;
		ft_btnode_replace(*bt, (*bt)->less);
	}
	else if ((*bt)->more)
	{
		p->subtree = (*bt)->more;
		ft_btnode_replace(*bt, (*bt)->more);
	}
	else
		_ft_btnode_remleaf(bt, p);
}

t_btree	*ft_btnode_remove(t_btree *bt, size_t key, t_fn1 fn)
{
	t_params	p;

	p.subtree = 0;
	p.nd = 0;
	p.fromchild = 0;
	p.root = bt;
	while (1)
	{
		p.parent = bt->parent;
		if (bt->key == key)
		{
			_ft_btnode_remove_1(&bt, fn, &p);
			break ;
		}
		else
		{
			if (_ft_btnode_remove_2(&bt, key) == 1)
				return (p.root);
		}
	}
	return (_ft_btnode_adj_subtree(&bt, fn, &p));
}
