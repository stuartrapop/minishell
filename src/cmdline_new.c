/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:06 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 10:22:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*cmdline_new(void)
{
	t_cmdline	*cl;

	cl = ft_calloc(1, sizeof(t_cmdline));
	if (!cl)
		return (0);
	if (!cmdline_init(cl))
	{
		ft_free(cl);
		return (0);
	}
	return (cl);
}
