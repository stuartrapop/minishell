/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:08:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/18 00:55:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_ro(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error("open", strerror(errno));
		return (-1);
	}
	return (fd);
}

int	open_file_wa(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		error("open", strerror(errno));
		return (-1);
	}
	return (fd);
}

int	open_file_wo(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
	{
		error("open", strerror(errno));
		return (-1);
	}
	return (fd);
}

int	open_file_heredoc(const char *eof)
{
	char	*line;
	int		pipes[2];

	if (pipe(pipes) == -1)
		return (-1 + error(0, "pipe"));
	while (1)
	{
		line = ft_getnextline(0);
		if (!line || comp_hd(line, eof))
			break ;
		ft_putstr(line, pipes[1]);
	}
	close(pipes[1]);
	return (pipes[0]);
}
