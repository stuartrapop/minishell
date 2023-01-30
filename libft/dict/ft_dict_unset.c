/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:56:09 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

static void	*_ft_dict_unset_1(t_dict **d, size_t h, t_dictnode *nd)
{
	void	*val;

	val = nd->val;
	ft_btree_rem(d, h, 0);
	ft_dictnode_del(&nd);
	return (val);
}

static void	*_ft_dict_unset_2(t_dict **d, char *key, size_t h, t_dictnode *nd)
{
	t_dictnode	*first;
	t_dictnode	*prev;
	void		*val;

	prev = 0;
	first = nd;
	while (nd)
	{
		if (!ft_strcmp(nd->key, key))
		{
			val = nd->val;
			if (nd == first)
			{
				if (ft_btree_ins(d, h, nd->next) < 1)
					return (0);
			}
			ft_sllist_take(&first, nd, prev);
			ft_dictnode_del(&nd);
			return (val);
		}
		prev = nd;
		nd = nd->next;
	}
	return (0);
}

void	*ft_dict_unset(t_dict **d, const char *key)
{
	t_dictnode	*nd;
	size_t		h;

	if (!*d || !*key)
		return (0);
	h = ft_dictnode_hash(key);
	nd = ft_btree_get(*d, h);
	if (!nd)
		return (0);
	if (!nd->next)
	{
		if (!ft_strcmp(nd->key, key))
			return (_ft_dict_unset_1(d, h, nd));
		return (0);
	}
	return (_ft_dict_unset_2(d, (char *)key, h, nd));
}
