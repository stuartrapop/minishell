/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnode_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:55:26 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	ft_dictnode_del(t_dictnode **nd)
{
	if (*nd)
	{
		ft_free(*nd);
		*nd = 0;
	}
}
