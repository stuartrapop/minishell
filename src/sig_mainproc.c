/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_mainproc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:51:34 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 15:05:11 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_kill_all(int signum)
{
	size_t	i;
	t_arr	*cmds;
	t_cmd	*cmd;

	assert(g_shell->_cmdgrp);
	cmds = &g_shell->_cmdgrp->cmds;
	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		if (cmd->_pid == -1)
			continue ;
		if (kill(cmd->_pid, signum) == -1)
			error("kill", strerror(errno));
	}
}

static void	_sig_int(void)
{
	if (g_shell->_cmdgrp)
	{
		_kill_all(SIGINT);
	}
	else if (g_shell->_in_builtin)
	{
		g_shell->_in_builtin = 0;
	}
	else
	{
		g_shell->retval = 2;
		rl_replace_line("", 1);
		ft_putstr("\n", 1);
		ft_putstr(ps1(), 1);
		rl_on_new_line_with_prompt();
	}
}

static void	_sig_quit(void)
{
	if (g_shell->_cmdgrp)
	{
		_kill_all(SIGQUIT);
	}
}

static void	_sig_handler(int signum)
{
	if (signum == SIGINT)
		_sig_int();
	else if (signum == SIGQUIT)
		_sig_quit();
}

/*
 *	1) save original signal handlers
 *	2) install our own
 */

void	sig_mainproc(void)
{
	struct sigaction	siga;

	assert(!g_shell->orig_sigint && !g_shell->orig_sigquit);
	g_shell->orig_sigint = ft_calloc(1, sizeof(struct sigaction));
	if (!g_shell->orig_sigint)
		enomem();
	g_shell->orig_sigquit = ft_calloc(1, sizeof(struct sigaction));
	if (!g_shell->orig_sigquit)
		enomem();
	ft_memset(&siga, 0, sizeof(struct sigaction));
	siga.sa_handler = &_sig_handler;
	if (sigaction(SIGINT, &siga, g_shell->orig_sigint) == -1)
		fatal("sigaction", strerror(errno));
	if (sigaction(SIGQUIT, &siga, g_shell->orig_sigquit) == -1)
		fatal("sigaction", strerror(errno));
}
