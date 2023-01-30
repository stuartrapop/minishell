/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:00:55 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 20:23:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_split_test(void)
{
	char	**arr;
	size_t	i;

	arr = ft_split("a:b:c:d", ':');
	i = 0;
	while (1)
	{
		if (arr[i])
			printf("%s\n", arr[i++]);
		else
			break ;
	}
}
