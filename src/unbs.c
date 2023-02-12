/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 19:30:35 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*unbs(const char *cmd)
{
	if (cmd[0] == '\\')
		return ((char *) &cmd[1]);
	return ((char *) cmd);
}
