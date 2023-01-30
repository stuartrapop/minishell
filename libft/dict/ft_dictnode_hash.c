/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnode_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:40:18 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:59:21 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dictnode_hash(const void *k)
{
	unsigned char	*p;
	size_t			h;
	size_t			i;
	const size_t	len = ft_strlen((char *) k);

	p = (unsigned char *) k;
	h = 0;
	i = 0;
	while (i < len)
	{
		h += p[i];
		h += (h << 10);
		h ^= (h >> 6);
		++i;
	}
	h += (h << 3);
	h ^= (h >> 11);
	h += (h << 15);
	return (h);
}
