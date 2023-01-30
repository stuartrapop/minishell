/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:02:03 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 10:11:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strncmp_test(void)
{
	char	a[30];
	char	b[30];

	ft_strcpy(a, "Testing stuff");
	ft_strcpy(b, "Testing stuff");

	assert(!ft_strncmp(a, b, 10) && !strncmp(a, b, 10));
	assert(ft_strncmp(a, "Testing", 8) == strncmp(a, "Testing", 8));
	assert(!ft_strncmp(a, "Testing", 7) && !strncmp(a, "Testing", 7));
	assert(!ft_strncmp(a, "Testing", 6) && !strncmp(a, "Testing", 6));
	assert(!ft_strncmp(a, "Test", 0) && !strncmp(a, "Test", 0));
	assert(!ft_strncmp(a, "", 0) && !strncmp(a, "", 0));
}
