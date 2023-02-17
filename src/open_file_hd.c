/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_hd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:15:49 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 13:00:54 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	_create_pipe(int fds[])
{
	if (pipe(fds) == -1)
		fatal("pipe", strerror(errno));
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

static int	_error(int fds[])
{
	errno = 0;
	fd_close(&fds[0]);
	fd_close(&fds[1]);
	return (-1);
}

static inline char	*_gnl(void)
{
	assert(errno == 0);
	return (ft_getnextline(0));
}

//	signal interrupts cause read to fail

int	open_file_hd(const char *eof)
{
	char	*line;
	int		fds[2];

	_create_pipe(fds);
	while (1)
	{
		ft_putstr("> ", 1);
		line = _gnl();
		if (!line)
		{
			ft_putstr("\n", 1);
			if (errno)
				return (_error(fds));
			break ;
		}
		if (_comp_hd(line, eof))
		{
			ft_free(line);
			break ;
		}
		ft_putstr(line, fds[1]);
		ft_del(&line);
	}
	fd_close(&fds[1]);
	return (fds[0]);
}