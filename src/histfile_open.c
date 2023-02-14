/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:44:28 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 19:03:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAXPATH	4096

int	histfile_open(int append)
{
	char	*home;
	char	path[MAXPATH];
	char	*p;

	home = ft_env_var("HOME", g_shell->env.data);
	if (!home || !ft_file_directory(home))
		return (-1);
	p = ft_stpcpy(path, home);
	ft_strcatchr(p, '/', 1);
	ft_strcat(p, HISTFILE);
	if (append)
	{
		if (ft_file_exists(path) && !ft_file_writable(path))
			return (-1);
		return (open(path, O_WRONLY | O_CREAT | O_APPEND, 0644));
	}
	if (ft_file_exists(path) && !ft_file_readable(path))
		return (-1);
	return (open(path, O_RDONLY | O_CREAT, 0644));
}
