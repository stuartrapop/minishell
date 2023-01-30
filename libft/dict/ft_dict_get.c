/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:33:48 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	*ft_dict_get(const t_dict *d, const char *key)
{
	size_t		h;
	t_dictnode	*nd;

	if (!d || !*key)
		return (0);
	h = ft_dictnode_hash(key);
	nd = ft_btree_get((t_btree *)d, h);
	while (nd)
	{
		if (*nd->key == *key && !ft_strcmp(nd->key, key))
			return (nd->val);
		nd = nd->next;
	}
	return (0);
}
