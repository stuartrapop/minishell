/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/24 00:55:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	*ft_arr_prepend(t_arr *a, void *p, t_fn2 copyfunc)
{
	return (ft_arr_insert(a, 0, p, copyfunc));
}
