/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:05:30 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 19:12:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	returned value ignored

int	histfile_add(const char *line)
{
	int	fd;

	fd = histfile_open(1);
	if (fd == -1)
		return (0);
	ft_putstr(line, fd);
	ft_putstr("\n", fd);
	fd_close(&fd);
	return (1);
}
