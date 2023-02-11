/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:08:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 23:24:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_ro(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
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
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
		return (-1);
	}
	return (fd);
}

int	open_file_wo(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
		return (-1);
	}
	return (fd);
}

static int	_comp_hd(const char *line, const char *hd)
{
	size_t	s1;
	size_t	s2;

	if (!ft_startswith(line, hd))
		return (0);
	if (ft_strlen2(line, &s1) == ft_strlen2(hd, &s2))
		return (1);
	if (s1 == s2 + 1 && ft_endswith(line, "\n"))
		return (1);
	return (0);
}

int	open_file_heredoc(const char *eof)
{
	char	*line;
	int		fds[2];

	if (pipe(fds) == -1)
		return (-1 + error("pipe", strerror(errno)));
	while (1)
	{
		ft_putstr("> ", 1);
		line = ft_getnextline(0);
		if (!line)
			break ;
		if (_comp_hd(line, eof))
		{
			ft_free(line);
			break ;
		}
		if (!ft_putstr(line, fds[1]))
		{
			ft_free(line);
			return (-1 + error("write", strerror(errno)));
		}
		ft_free(line);
	}
	close(fds[1]);
	return (fds[0]);
}
