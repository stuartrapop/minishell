/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:01:09 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 23:41:01 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_init(t_cmd *cmd)
{
	ft_memset(&cmd->_io, -1, sizeof(int) * 2);
	if (!ft_arr_init(&cmd->args, 1, sizeof(char *))
		|| !ft_arr_init(&cmd->inputs, 0, sizeof(char *))
		|| !ft_arr_init(&cmd->outputs, 0, sizeof(char *))
		|| !ft_arr_init(&cmd->heredocs, 0, sizeof(char *))
		|| !ft_arr_init(&cmd->appends, 0, sizeof(char *)))
		return (0);
	return (1);
}
