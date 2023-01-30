/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:46:00 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:57:21 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	ft_dict_del(t_dict **d, t_fn1 fn)
{
	if (fn)
		ft_dict_trav(*d, fn);
	ft_btree_del(d, (t_fn1) & ft_dictnode_list_del);
}
