/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:03:37 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 01:17:03 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmdline_init(t_cmdline *cl)
{
	if (!ft_arr_init(&cl->cmds, 1, sizeof(t_cmd *)))
		return (0);
	return (1);
}
