/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_hd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:15:49 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 16:35:41 by srapopor         ###   ########.fr       */
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

//  assert(errno == 0); line removed
static inline char	*_gnl(void)
{
	errno = 0;
	return (ft_getnextline(0));
}

static char	*expand_line(char **line)
{
	char	*tmp;
	char	*exp_line;

	(*line)[ft_strlen(*line) - 1] = '\0';
	tmp = exp_env_str(*line);
	exp_line = ft_calloc(ft_strlen(tmp) + 2, sizeof(char));
	ft_strccpy(exp_line, tmp, ft_strlen(tmp));
	exp_line[ft_strlen(tmp)] = '\n';
	ft_del(line);
	ft_del(&tmp);
	return (exp_line);
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
		line = expand_line(&line);
		ft_putstr(line, fds[1]);
		ft_del(&line);
	}
	fd_close(&fds[1]);
	return (fds[0]);
}
