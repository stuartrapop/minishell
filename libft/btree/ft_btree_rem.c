/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:53:57 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 23:03:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_rem(t_btree **bt, size_t key, t_fn1 fn)
{
	if (!*bt)
		return ;
	*bt = ft_btnode_remove(*bt, key, fn);
}
