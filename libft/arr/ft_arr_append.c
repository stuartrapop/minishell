/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:45:53 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/24 00:52:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	*ft_arr_append(t_arr *a, void *p, t_fn2 copyfunc)
{
	return (ft_arr_insert(a, a->nelem, p, copyfunc));
}
