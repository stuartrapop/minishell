/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:44:20 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 02:56:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include "libft.h"

# ifndef NDEBUG
#  include <assert.h>
#  include <stdio.h>
# endif

/*
 *	self-balanced binary tree
 */

typedef struct s_btree
{
	size_t			key;
	void			*val;
	struct s_btree	*parent;
	struct s_btree	*less;
	struct s_btree	*more;
	int				bfactor : 2;
}	t_btree;

t_btree		*ft_btree_least(const t_btree *bt);
t_btree		*ft_btree_most(const t_btree *bt);
t_btree		*ft_btree_next(const t_btree *bt);
t_btree		*ft_btree_prev(const t_btree *bt);
t_btree		*ft_btree_root(const t_btree *bt);

size_t		ft_btree_count(const t_btree *bt);
size_t		ft_btree_trav(const t_btree *bt, t_fn1 fn, int reverse);
size_t		ft_btree_trav2(const t_btree *bt, t_fn2 fn, void *udata, int rev);

void		ft_btree_del(t_btree **bt, t_fn1 fn);
void		*ft_btree_get(const t_btree *bt, size_t key);
int			ft_btree_ins(t_btree **bt, size_t key, void *val);
void		ft_btree_rem(t_btree **bt, size_t key, t_fn1 fn);

/*
 *	PRIVATE STUFF
 */

void		ft_btnode_del(t_btree **bt, t_fn1 fn);
int			ft_btnode_insert(t_btree **bt, size_t k, void *v, t_btree *parent);
void		ft_btnode_inserted(t_btree *z);
int			ft_btnode_new(t_btree **bt, size_t k, void *v, const t_btree *p);
void		ft_btnode_replace(t_btree *bt, t_btree *nd);
t_btree		*ft_btnode_remove(t_btree *bt, size_t key, t_fn1 fn);
void		ft_btnode_removed(t_btree *n, t_btree *x, int fromchild);
t_btree		*ft_btnode_rotate_left(t_btree *x, t_btree *z);
t_btree		*ft_btnode_rotate_leftright(t_btree *x, t_btree *z);
t_btree		*ft_btnode_rotate_right(t_btree *x, t_btree *z);
t_btree		*ft_btnode_rotate_rightleft(t_btree *x, t_btree *z);

# ifndef NDEBUG

void		ft_btnode_debug(const t_btree *bt);

# endif

#endif
