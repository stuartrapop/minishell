/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:52:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/26 19:23:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_fini(t_cmd *cl)
{
	size_t	i;

	i = -1;
	while (++i < 3)
		if (cl->io[i] != -1)
			close(cl->io[i]);
	return (0);
}
