/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:48:29 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 13:09:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strnlen_test(void)
{
	char	a[10];

	ft_memset(a, 42, 10);
	assert(ft_strnlen(a, 0) == strnlen(a, 0));
	assert(ft_strnlen(a, 1) == strnlen(a, 1));
	assert(ft_strnlen(a, 10) == strnlen(a, 10));

	assert(ft_strnlen("4242", 0) == strnlen("4242", 0));
	assert(ft_strnlen("4242", 1) == strnlen("4242", 1));
	assert(ft_strnlen("4242", 3) == strnlen("4242", 3));
	assert(ft_strnlen("4242", 4) == strnlen("4242", 4));
	assert(ft_strnlen("4242", 5) == strnlen("4242", 5));
}
