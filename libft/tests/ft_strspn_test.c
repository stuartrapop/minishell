/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:42:57 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/30 16:46:13 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strspn_test(void)
{
	assert(ft_strspn("abcd", "a") == strspn("abcd", "a"));
	assert(ft_strspn("aabcd", "a") == strspn("aabcd", "a"));
	assert(ft_strspn("aaabcd", "a") == strspn("aaabcd", "a"));
	assert(ft_strspn("aaaabcd", "a") == strspn("aaaabcd", "a"));
	assert(ft_strspn("aaaaabcd", "a") == strspn("aaaaabcd", "a"));
	assert(ft_strspn("aaaaaabcd", "a") == strspn("aaaaaabcd", "a"));
}
