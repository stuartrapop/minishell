/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:54:55 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/17 20:27:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	*ft_arr_insert(t_arr *a, size_t idx, void *p, t_fn2 copyfunc)
{
	void	*dest;

	if (idx > a->nelem)
		return (0);
	if (!a->ncapacity || a->nelem == a->ncapacity - 1)
	{
		if (!ft_arr_reserve(a, ft_ulmax(a->ncapacity, 1) * 2))
			return (0);
	}
	dest = a->data + (idx * a->unit);
	ft_memmove(dest + a->unit, dest, (a->nelem - idx) * a->unit);
	if (copyfunc)
		(*copyfunc)(dest, p);
	else
		ft_memcpy(dest, p, a->unit);
	++(a->nelem);
	return (dest);
}
