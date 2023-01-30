/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_trav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:51:35 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	ft_dict_trav(t_dict *d, t_fn1 fn)
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
			(*fn)(n);
			n = n->next;
		}
		nd = ft_btree_next(nd);
	}
}
