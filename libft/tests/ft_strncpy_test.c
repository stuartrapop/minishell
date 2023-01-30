/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:52:56 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/30 16:45:24 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strncpy_test(void)
{
	char	a[10];
	char	b[10];

	ft_memset(a, 0, 10);
	ft_memset(b, 0, 10);

	ft_strncpy(a, "01234", 10);
	strncpy(b, "01234", 10);
	assert(ft_memcmp(a, b, 10) == memcmp(a, b, 10));

	ft_strncpy(a, "42", 10);
	strncpy(b, "42", 10);
	assert(ft_memcmp(a, b, 10) == memcmp(a, b, 10));

	/* ft_strncpy(a, "4242424242", 10); */
	/* strncpy(b, "4242424242", 10); */
	/* assert(ft_memcmp(a, b, 10) == memcmp(a, b, 10)); */
}
