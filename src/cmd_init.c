/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:01:09 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/26 19:23:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_init(t_cmd *cl)
{
	ft_memset(cl, 0, sizeof(t_cmd));
	ft_memset(&cl->io, -1, sizeof(int) * 3);
	return (1);
}
