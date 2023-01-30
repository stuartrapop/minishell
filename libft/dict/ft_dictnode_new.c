/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnode_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:42:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

void	*ft_dictnode_new(t_dictnode **nd, const char *k, void *v)
{
	*nd = ft_malloc(sizeof(t_dictnode) + (ft_strlen(k) + 1));
	if (!*nd)
		return (0);
	(*nd)->next = 0;
	(*nd)->val = v;
	ft_strcpy((*nd)->key, k);
	return (*nd);
}
