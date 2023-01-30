/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:06:27 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 03:28:54 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_memory_test(void)
{
	t_memlist	**m;
	char		*p;

	ft_memtrash();
	m = ft_memlist();
	/* assert(*m == 0); */
	p = ft_malloc(4);
	assert(p);
	assert(ft_memusage() == 4);
	ft_strcpy(p, "123");
	assert(ft_strlen(p) == 3);
	assert(*m != 0);
	p = ft_realloc(p, 8);
	assert(p);
	assert(ft_memusage() == 8);
	strcat(p, "1234");
	assert(ft_strcmp(p, "1231234") == 0);
	ft_free(p);
	/* assert(*m == 0); */
	assert(ft_memusage() == 0);
}
