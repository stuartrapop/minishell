/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:44:58 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 09:45:09 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memmove_test(void)
{
	char	a[10];
	char	b[10];

	ft_memset(a, 0, 10);
	ft_memset(b, 0, 10);
	*a = 42;
	*b = 42;
	a[1] = 24;
	b[1] = 24;
	assert(ft_memmove(a + 1, a, 2) == a + 1);
	assert(memmove(b + 1, b, 2) == b + 1);
	assert(ft_memcmp(a, b, 10) == 0);
	assert(a[0] == 42 && b[0] == 42);
	assert(a[1] == 42 && b[1] == 42);
	assert(a[2] == 24 && b[2] == 24);
	assert(a[3] == 0 && b[3] == 0);
}
