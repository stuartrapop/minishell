/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 02:39:41 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strlen_test(void)
{
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("42") == strlen("42"));
	assert(ft_strlen("4242") == strlen("4242"));
}
