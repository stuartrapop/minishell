/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:21:55 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/18 00:58:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_btree.h"

void	ft_btnode_del(t_btree **bt, t_fn1 fn)
{
	if (*bt)
	{
		if (fn)
			(*fn)((*bt)->val);
		ft_free(*bt);
		*bt = 0;
	}
}
