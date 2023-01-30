/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:42:07 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 02:42:10 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strcmp_test(void)
{
	assert(ft_strcmp("", "") == strcmp("", ""));
	assert(ft_strcmp("a", "") == strcmp("a", ""));
	assert(ft_strcmp("", "a") == strcmp("", "a"));
	assert(ft_strcmp("a", "a") == strcmp("a", "a"));
	assert(ft_strcmp("aa", "aa") == strcmp("aa", "aa"));
	assert(ft_strcmp("a", "aa") == strcmp("a", "aa"));
	assert(ft_strcmp("aa", "a") == strcmp("aa", "a"));
	assert(ft_strcmp("azaz", "zaza") == strcmp("azaz", "zaza"));
}
