/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:27:19 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/15 22:45:22 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	reinstall original signal handlers

void	sig_remove(void)
{
	assert(g_shell->orig_sigint && g_shell->orig_sigquit);
	if (sigaction(SIGINT, g_shell->orig_sigint, 0) == -1)
		fatal("sigaction", strerror(errno));
	if (sigaction(SIGQUIT, g_shell->orig_sigquit, 0) == -1)
		fatal("sigaction", strerror(errno));
}
