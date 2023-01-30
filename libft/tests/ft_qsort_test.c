/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:37:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/21 15:22:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static int	_compar(int *a, int *b)
{
	return (*a - *b);
}

void	ft_qsort_test(void)
{
	size_t i;
	int	arr[5] = {3, 1, 2, 4, 0};

	ft_qsort(arr, 5, sizeof(int), (t_compar) &_compar);
	i = 0;
	while (i < 5)
		printf("%d\n", arr[i++]);
}
