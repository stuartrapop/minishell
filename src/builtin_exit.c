/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 05:18:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(t_cmdline *cl, t_cmd *cmd, t_shell *sh)
{
	(void) cl;
	(void) cmd;
	(void) sh;
	return (1);
}
