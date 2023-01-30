/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multovf_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:04:47 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 09:53:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_multovf_test(void)
{
	assert(ft_multovf((size_t) -1, 0) == 0);
	assert(ft_multovf((size_t) -1, 1) == 0);
	assert(ft_multovf((size_t) -1, 2) == 1);
	assert(ft_multovf(0, 0) == 0);
	assert(ft_multovf((size_t) -1, 2) == 1);
	assert(ft_multovf(((size_t) -1 / 2) + 0, 2) == 0);
	assert(ft_multovf(((size_t) -1 / 2) + 1, 2) == 1);
}
