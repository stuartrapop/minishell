/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_most.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:46:02 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:57:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btree_most(const t_btree *bt)
{
	if (!bt)
		return (0);
	while (bt->more)
		bt = bt->more;
	return ((t_btree *) bt);
}
