/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:00:55 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 18:58:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_load_history(char **lines)
{
	size_t	i;
	char	*line;

	i = -1;
	while (lines[++i])
	{
		line = lines[i];
		if (ft_strisspace(line))
			continue ;
		if (ft_endswith(line, "\n"))
			*ft_strrchr(line, '\n') = 0;
		add_history(line);
	}
}

//	returned value ignored

int	histfile_load(void)
{
	int		fd;
	char	**lines;

	fd = histfile_open(0);
	if (fd == -1)
		return (0);
	lines = ft_getfile(fd);
	if (!lines)
		enomem();
	_load_history(lines);
	ft_del_arr(&lines);
	fd_close(&fd);
	return (1);
}
