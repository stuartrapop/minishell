/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:17 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 16:19:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strncasecmp_test(void)
{
	assert(ft_strncasecmp("", "", 1) == strncasecmp("", "", 1));
	assert(ft_strncasecmp("", " ", 1) == strncasecmp("", " ", 1));
	assert(ft_strncasecmp(" ", "", 1) == strncasecmp(" ", "", 1));
	assert(ft_strncasecmp("Hello", "World", 3) == strncasecmp("Hello", "World", 3));
	assert(ft_strncasecmp("Hello", "Hella", 3) == strncasecmp("Hello", "Hella", 3));
	assert(ft_strncasecmp("Hello", "HELLO", 3) == strncasecmp("Hello", "HELLO", 3));
	assert(ft_strncasecmp("Hello", "Hello", 3) == strncasecmp("Hello", "Hello", 3));
	assert(ft_strncasecmp("Hello", "HeLLo", 3) == strncasecmp("Hello", "HeLLo", 3));
	assert(ft_strncasecmp("Hello", "World", 3) == strncasecmp("Hello", "World", 3));
	assert(ft_strncasecmp("Hello", "World", 5) == strncasecmp("Hello", "World", 5));
	assert(ft_strncasecmp("Hello", "Hella", 5) == strncasecmp("Hello", "Hella", 5));
	assert(ft_strncasecmp("Hello", "HELLO", 5) == strncasecmp("Hello", "HELLO", 5));
	assert(ft_strncasecmp("Hello", "Hello", 5) == strncasecmp("Hello", "Hello", 5));
	assert(ft_strncasecmp("Hello", "HeLLo", 5) == strncasecmp("Hello", "HeLLo", 5));
	assert(ft_strncasecmp("Hello", "World", 5) == strncasecmp("Hello", "World", 5));
	assert(ft_strncasecmp("Hello", "World", 7) == strncasecmp("Hello", "World", 7));
	assert(ft_strncasecmp("Hello", "Hella", 7) == strncasecmp("Hello", "Hella", 7));
	assert(ft_strncasecmp("Hello", "HELLO", 7) == strncasecmp("Hello", "HELLO", 7));
	assert(ft_strncasecmp("Hello", "Hello", 7) == strncasecmp("Hello", "Hello", 7));
	assert(ft_strncasecmp("Hello", "HeLLo", 7) == strncasecmp("Hello", "HeLLo", 7));
	assert(ft_strncasecmp("Hello", "World", 7) == strncasecmp("Hello", "World", 7));
}
