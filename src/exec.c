/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 19:23:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_node *root, char *environ[])
{
	static t_arr	*env;

	if (!env)
	{
		env = env_dup(environ);
		if (!env)
		{
			error(0, "nomem");
			return ;
		}
	}
	(void) root;
}
