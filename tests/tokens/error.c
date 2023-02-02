/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:54:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 14:16:09 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	error(const char *title, const char *msg)
{
	if (title && *title)
		ft_dprintf(2, "error: %s: %s\n", title, msg);
	else
		ft_dprintf(2, "error: %s\n", msg);
	return (0);
}
