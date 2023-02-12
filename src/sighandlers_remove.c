/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandlers_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:27:19 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 03:53:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sighandlers_remove(void)
{
	assert(g_shell->orig_sigint);
	if (sigaction(SIGINT, g_shell->orig_sigint, 0))
		return (error("sigaction", strerror(errno)));
	return (1);
}