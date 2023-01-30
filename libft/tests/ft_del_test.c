/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:00:55 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 20:14:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_del_test(void)
{
	char	**tab;

	tab = ft_split("a:b:c:d", ':');
	printf("memusage = %zu\n", ft_memusage());
	ft_del_arr(&tab);
	printf("memusage = %zu\n", ft_memusage());
}
