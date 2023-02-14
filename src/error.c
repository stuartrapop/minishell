/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:54:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 14:45:16 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(const char *title, const char *msg)
{
	if (title && *title)
		ft_dprintf(2, "error: %s: %s\n", title, msg);
	else
		ft_dprintf(2, "error: %s\n", msg);
	errno = 0;
	return (0);
}

int	enomem(void)
{
	error(0, "nomem");
	exit(1);
	return (0);
}

int	fatal(const char *title, const char *msg)
{
	error(title, msg);
	return (finish(1));
}
