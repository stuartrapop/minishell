/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:52:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/04 01:42:32 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_fini(void *command)
{
	t_cmd	*cmd;

	cmd = *(t_cmd **) command;
	ft_arr_fini(&cmd->args, &ft_del);
	ft_arr_fini(&cmd->inputs, &ft_del);
	ft_arr_fini(&cmd->outputs, &ft_del);
	ft_arr_fini(&cmd->heredocs, &ft_del);
	ft_arr_fini(&cmd->appends, &ft_del);
	ft_del_arr(&cmd->env);
	close(cmd->_io[0]);
	close(cmd->_io[1]);
}
