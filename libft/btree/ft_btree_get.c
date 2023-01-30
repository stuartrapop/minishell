/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:59:53 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*ft_btree_get(const t_btree *bt, size_t key)
{
	while (1)
	{
		if (!bt)
			return (0);
		if (key == bt->key)
			return (bt->val);
		if (key < bt->key)
			bt = bt->less;
		else
			bt = bt->more;
	}
}
