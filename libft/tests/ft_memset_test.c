/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:45:17 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 09:45:19 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memset_test(void)
{
	char	a[10];
	char	b[10];

	assert(ft_memset(a, 42, 10) == a);
	assert(memset(b, 42, 10) == b);
	assert(memcmp(a, b, 10) == 0);
	assert(ft_memcmp(a, b, 10) == 0);
}
