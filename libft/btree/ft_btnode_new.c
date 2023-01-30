/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:35:24 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:58:29 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_btree.h"

int	ft_btnode_new(t_btree **bt, size_t key, void *val, const t_btree *parent)
{
	*bt = ft_malloc(sizeof(t_btree));
	if (!*bt)
		return (0);
	(*bt)->key = key;
	(*bt)->val = val;
	(*bt)->parent = (t_btree *) parent;
	(*bt)->less = 0;
	(*bt)->more = 0;
	(*bt)->bfactor = 0;
	return (1);
}
