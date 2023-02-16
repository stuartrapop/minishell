/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:38 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/15 16:19:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	save original termios settings

void	termios_init(void)
{
	if (tcgetattr(0, &g_shell->orig_termios) == -1)
		fatal("tcgetattr", strerror(errno));
}
