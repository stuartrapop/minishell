/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:49:15 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 10:50:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_del(t_cmd **cmd)
{
	cmd_fini(*cmd);
	ft_free(*cmd);
	*cmd = 0;
	return (0);
}
