/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_remove.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:55:50 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:29:46 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTNODE_REMOVE_H
# define FT_BTNODE_REMOVE_H

typedef struct s_params
{
	t_btree	*root;
	t_btree	*parent;
	t_btree	*subtree;
	t_btree	*nd;
	int		fromchild;
}	t_params;

static void	_ft_btnode_remleaf(t_btree **bt, t_params *p)
{
	if (p->parent)
	{
		if (*bt == p->parent->less)
			p->fromchild = -1;
		else
			p->fromchild = 1;
	}
	else
		p->root = 0;
	ft_btnode_replace(*bt, 0);
}

static int	_ft_btnode_remove_2(t_btree **bt, size_t key)
{
	if (key < (*bt)->key)
		*bt = (*bt)->less;
	else
		*bt = (*bt)->more;
	if (!*bt)
		return (1);
	return (0);
}

static t_btree	*_ft_btnode_adj_subtree(t_btree **bt, t_fn1 fn, t_params *p)
{
	if (p->root)
	{
		if (p->parent)
			ft_btnode_removed(p->subtree, p->parent, p->fromchild);
		else
			ft_btnode_removed(p->subtree, p->root, p->fromchild);
		if (p->root != *bt)
			p->root = ft_btree_root(p->root);
		else if ((*bt)->less)
			p->root = ft_btree_root((*bt)->less);
		else
			p->root = ft_btree_root((*bt)->more);
	}
	ft_btnode_del(bt, fn);
	return (p->root);
}

#endif
