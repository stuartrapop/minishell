/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:38:28 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 00:47:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getnext.h"

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	**file;
	size_t	i;

	fd = open("test.txt", O_RDONLY);
	file = ft_getfile(fd);
	i = 0;
	while (file[i])
		printf("%s", file[i++]);
	ft_del_arr(&file);
	return (0);
}
