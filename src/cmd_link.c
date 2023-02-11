/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:12:00 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 19:15:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_link(t_cmd *cmd)
{
	if (cmd->_io[0] != -1)
	{
		if (dup2(cmd->_io[0], 0) == -1)
			return (error("dup2", strerror(errno)));
		fd_close(&cmd->_io[0]);
	}
	if (cmd->_io[1] != -1)
	{
		if (dup2(cmd->_io[1], 1) == -1)
			return (error("dup2", strerror(errno)));
		fd_close(&cmd->_io[1]);
	}
	return (1);
}
