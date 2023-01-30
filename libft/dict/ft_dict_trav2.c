/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_trav2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:52:23 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	ft_dict_trav2(t_dict *d, t_fn2 fn, void *userdata)
{
	t_btree		*nd;
	t_dictnode	*n;

	if (!d || !fn)
		return ;
	nd = ft_btree_least(d);
	while (nd)
	{
		n = nd->val;
		while (n)
		{
			(*fn)(n, userdata);
			n = n->next;
		}
		nd = ft_btree_next(nd);
	}
}
