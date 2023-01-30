/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:17:30 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void	_ft_btnode_replace_4(t_btree *bt, t_btree *nd)
{
	nd->less = bt->less;
	if (bt->less)
		bt->less->parent = nd;
}

static void	_ft_btnode_replace_3(t_btree *bt, t_btree *nd)
{
	nd->more = bt->more;
	if (bt->more)
		bt->more->parent = nd;
}

static void	_ft_btnode_replace_2(t_btree *bt, t_btree *nd)
{
	if (bt->less)
	{
		bt->less->parent = nd;
		nd->less = bt->less;
	}
	nd->parent->less = nd->more;
	if (nd->more)
		nd->more->parent = nd->parent;
	nd->more = bt->more;
	bt->more->parent = nd;
}

static void	_ft_btnode_replace_1(t_btree *bt, t_btree *nd)
{
	if (bt->more)
	{
		bt->more->parent = nd;
		nd->more = bt->more;
	}
	nd->parent->more = nd->less;
	if (nd->less)
		nd->less->parent = nd->parent;
	nd->less = bt->less;
	bt->less->parent = nd;
}

void	ft_btnode_replace(t_btree *bt, t_btree *nd)
{
	if (bt->parent)
	{
		if (bt == bt->parent->less)
			bt->parent->less = nd;
		else
			bt->parent->more = nd;
	}
	if (nd)
	{
		if (nd != bt->less && nd != bt->more)
		{
			if (nd->key < bt->key)
				_ft_btnode_replace_1(bt, nd);
			else
				_ft_btnode_replace_2(bt, nd);
		}
		else if (nd == bt->less)
			_ft_btnode_replace_3(bt, nd);
		else
			_ft_btnode_replace_4(bt, nd);
		nd->parent = bt->parent;
	}
}
