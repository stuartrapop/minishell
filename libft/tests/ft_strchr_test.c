/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:45:27 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 09:46:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_strchr_test(void)
{
	int		i;
	char	a[10];

	ft_strcpy(a, "012345678");
	i = 0;
	while (i < 9)
	{
		assert(ft_strchr(a, '0' + i) == &a[i]);
		assert(ft_strchr(a, '0' + i) == strchr(a, '0' + i));
		++i;
	}
	assert(ft_strchr(a, '9') == 0 && strchr(a, '9') == 0);
}
