/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:38:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 10:41:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return the last cmd in the list (or create one)

t_cmd	*cmdline_cmd(t_cmdline *cl)
{
	t_cmd	*cmd;

	if (cl->cmds.nelem == 0)
	{
		cmd = cmd_new();
		if (!cmd)
		{
			error("cmd_new", "nomem");
			return (0);
		}
		if (!ft_arr_append(&cl->cmds, cmd, 0))
		{
			ft_free(cmd);
			error("ft_arr_append", "nomem");
			return (0);
		}
	}
	else
		cmd = *(t_cmd **) ft_arr_get(&cl->cmds, cl->cmds.nelem - 1);
	return (cmd);
}
