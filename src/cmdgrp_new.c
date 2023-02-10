/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:06 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 08:29:25 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmdgrp_init(t_cmdgrp *cl)
{
	if (!ft_arr_init(&cl->cmds, 1, sizeof(t_cmd *)))
		return (0);
	return (1);
}

t_cmdgrp	*cmdgrp_new(void)
{
	t_cmdgrp	*cl;

	cl = ft_calloc(1, sizeof(t_cmdgrp));
	if (!cl)
		return (0);
	if (!cmdgrp_init(cl))
	{
		ft_free(cl);
		return (0);
	}
	return (cl);
}
