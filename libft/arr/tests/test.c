/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:31 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/23 16:00:30 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

static void	_print(int *i)
{
	printf("%d\n", *i);
}

int	main(void)
{
	int		i;
	t_arr	a;

	ft_arr_init(&a, 1, sizeof(int));

	i = 42;
	ft_arr_append(&a, &i, 0);
	ft_arr_trav(&a, (t_fn1) &_print);

	i = *(int *)ft_arr_get(&a, 0);
	assert(i == 42);

	i = 52;
	ft_arr_append(&a, &i, 0);
	ft_arr_trav(&a, (t_fn1) &_print);

	ft_arr_fini(&a, 0);

	printf("Memusage = %zu\n", ft_memusage());
	return (0);
}
