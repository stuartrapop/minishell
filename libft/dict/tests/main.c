/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 03:07:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 03:53:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ft_dict.h"

char	randchar(void)
{
	return ('a' + (random() % 26));
}

char	*randword_sz(size_t sz)
{
	char	*s;
	char	*ret;
	size_t	i;

	s = ft_malloc(sizeof(char) * (sz + 1));
	if (!s)
		return (0);
	ret = s;
	i = 0;
	while (i++ < sz)
		*s++ = randchar();
	*s = 0;
	return (ret);
}

char	*randword(void)
{
	return (randword_sz((random() % 16) + 10));
}


int main(void)
{
	t_dict	*d;
	char	*words[1000];
	char	*got;
	size_t	i;

	srandom(time(0));
	d = 0;
	i = 0;
	while (i < 1000)
	{
		got = randword();
		if (!ft_dict_set(&d, got, got, 0))
		{ // duplicate key
			words[i] = 0;
			ft_free(got);
		}
		else
			words[i] = got;
		++i;
	}
	i = 0;
	while (i < 1000)
	{
		got = ft_dict_get(d, words[i]);
		if (got)
			printf("Got: %s\n", got);
		++i;
	}
	i = 0;
	while (i < 1000)
	{
		got = ft_dict_unset(&d, words[i]);
		ft_free(got);
		++i;
	}
	printf("Memusage = %zu\n", ft_memusage());
	return (0);
}
