/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:38:56 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 20:41:09 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_startswith_test(void)
{
	assert(ft_startswith("abcd", "a"));
	assert(ft_startswith("abcd", "ab"));
	assert(ft_startswith("abcd", "abc"));
	assert(ft_startswith("abcd", "abcd"));

	assert(!ft_startswith("abcd", "abcde"));
	assert(!ft_startswith("abcd", "xyz"));
	assert(!ft_startswith("abcd", ""));
	assert(!ft_startswith("", "abcde"));
}
