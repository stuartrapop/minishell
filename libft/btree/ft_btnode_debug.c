/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:09:51 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/06 00:04:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "../printf/ft_printf.h"

void	ft_btnode_debug(const t_btree *bt)
{
	ft_printf("=== NODE ===\n"
		"self= %p\n"
		"key = %zu\n"
		"bfac= %d\n"
		"par = %p\n"
		"less= %p\n"
		"more= %p\n",
		bt, bt->key, bt->bfactor, bt->parent, bt->less, bt->more);
}
