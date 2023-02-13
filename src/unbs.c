/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 01:04:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*unbs(char **cmd)
{
	char	*p;

	assert(*cmd);
	if (**cmd == '\\')
	{
		p = *cmd;
		*cmd = ft_strdup(&(*cmd)[1]);
		if (!*cmd)
			enomem();
		ft_free(p);
	}
	return (*cmd);
}
