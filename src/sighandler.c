/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:51:34 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 23:57:24 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_int(void)
{
	size_t	i;
	t_cmd	*cmd;

	if (g_shell->cmdgrp)
	{
		i = -1;
		while (++i < g_shell->cmdgrp->cmds.nelem)
		{
			cmd = *(t_cmd **) ft_arr_get(&g_shell->cmdgrp->cmds, i);
			if (cmd->_pid == -1)
				continue ;
			if (kill(cmd->_pid, SIGINT) == -1)
				error("kill", strerror(errno));
		}
	}
	else
	{
		rl_replace_line("", 1);
		ft_putstr("\n" PS1, 1);
		rl_on_new_line_with_prompt();
	}
}

static void	_sig_handler(int i)
{
	if (i == SIGINT)
		_sig_int();
}

int	install_sighandler(void)
{
	struct sigaction	siga;

	ft_memset(&siga, 0, sizeof(struct sigaction));
	siga.sa_handler = &_sig_handler;
	if (sigaction(SIGINT, &siga, 0))
		return (error("sigaction", strerror(errno)));
	return (1);
}
