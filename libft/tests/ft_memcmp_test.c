/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:44:31 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 13:07:06 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memcmp_test(void)
{
	char	a[10];
	char	b[10];

	a[9] = 0;
	b[9] = 0;
	assert(ft_memcmp(a, b, 0) == 0);
	assert(memcmp(a, b, 0) == 0);

	ft_memset(a, 42, 9);
	ft_memset(b, 42, 9);
	assert(ft_memcmp(a, b, 10) == memcmp(a, b, 10));
	assert(ft_strcmp(a, "*********") == strcmp(a, b));

	ft_memset(a + 1, 0, 3);
	ft_memset(b + 1, 0, 3);
	assert(ft_memcmp(a, b, 10) == memcmp(a, b, 10));
	assert(ft_strcmp(a, "*") == strcmp(a, b));
	assert(a[3] == 0 && a[3] == b[3]);
	assert(a[4] == 42 && a[4] == b[4]);
}
