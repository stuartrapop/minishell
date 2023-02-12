/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandlers_install.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:51:34 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 03:50:57 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_int(void)
{
	size_t	i;
	t_cmd	*cmd;

	if (g_shell->_cmdgrp)
	{
		i = -1;
		while (++i < g_shell->_cmdgrp->cmds.nelem)
		{
			cmd = *(t_cmd **) ft_arr_get(&g_shell->_cmdgrp->cmds, i);
			if (cmd->_pid == -1)
				continue ;
			if (kill(cmd->_pid, SIGINT) == -1)
				error("kill", strerror(errno));
		}
	}
	else
	{
		rl_replace_line("", 1);
		ft_putstr("\n", 1);
		ft_putstr(ps1(), 1);
		rl_on_new_line_with_prompt();
	}
}

static void	_sig_handler(int i)
{
	if (i == SIGINT)
		_sig_int();
}

int	sighandlers_install(void)
{
	struct sigaction	siga;

	if (!g_shell->orig_sigint)
	{
		g_shell->orig_sigint = ft_calloc(1, sizeof(struct sigaction));
		if (!g_shell->orig_sigint)
			return (enomem());
	}
	ft_memset(&siga, 0, sizeof(struct sigaction));
	siga.sa_handler = &_sig_handler;
	if (sigaction(SIGINT, &siga, g_shell->orig_sigint))
		return (error("sigaction", strerror(errno)));
	return (1);
}
