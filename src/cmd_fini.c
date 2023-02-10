/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:52:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 14:38:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_fini(void *command)
{
	t_cmd	*cmd;

	cmd = *(t_cmd **) command;
	ft_arr_fini(&cmd->args, &ft_del);
	ft_arr_fini(&cmd->redirs, &redir_fini);
	close(cmd->_io[0]);
	close(cmd->_io[1]);
}
