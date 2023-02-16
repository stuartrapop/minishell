/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:17:11 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 14:40:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	disable/enable ctrl-\ (sigquit)
//	echoctl disabled

void	termios_bs(int enable)
{
	struct termios	st_t;

	ft_memcpy(&st_t, &g_shell->orig_termios, sizeof(struct termios));
	st_t.c_lflag &= ~ECHOCTL;
	if (enable)
		st_t.c_cc[VQUIT] = 034;
	else
		st_t.c_cc[VQUIT] = _POSIX_VDISABLE;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &st_t) == -1)
		fatal("tcsetattr", strerror(errno));
}
