/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:15:29 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 18:21:34 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_file_directory(const char *path)
{
	struct stat	sstat;

	if (stat(path, &sstat) == -1)
		return (0);
	if (S_ISDIR(sstat.st_mode))
		return (1);
	return (0);
}
