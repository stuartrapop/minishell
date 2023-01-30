/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:51:34 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/30 15:45:07 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_int(void)
{
	// if (kill(0, SIGINT))
	// 	error(0, "kill");
	rl_replace_line("", 1);
	ft_putstr("\n" PS1, 1);
	rl_on_new_line_with_prompt();
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
		return (error(0, "sigaction"));
	return (1);
}
