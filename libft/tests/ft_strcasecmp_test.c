/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:17 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 16:48:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strcasecmp_test(void)
{
	assert(ft_strcasecmp("", "") == strcasecmp("", ""));
	assert(ft_strcasecmp("", " ") == strcasecmp("", " "));
	assert(ft_strcasecmp(" ", "") == strcasecmp(" ", ""));
	assert(ft_strcasecmp("Hello", "WorlD") == strcasecmp("Hello", "World"));
	assert(ft_strcasecmp("Hello", "Hella") == strcasecmp("Hello", "Hella"));
	assert(ft_strcasecmp("Hello", "HELLO") == strcasecmp("Hello", "HELLO"));
	assert(ft_strcasecmp("Hello", "Hello") == strcasecmp("Hello", "Hello"));
	assert(ft_strcasecmp("Hello", "HeLLo") == strcasecmp("Hello", "HeLLo"));
	assert(ft_strcasecmp("Hello", "World") == strcasecmp("Hello", "World"));
}
