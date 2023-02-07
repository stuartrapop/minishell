/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:06:15 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 00:08:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_init(t_shell *sh, char *environ[])
{
	ft_memset(sh, 0, sizeof(t_shell));
	if (!env_dup(&sh->env, environ))
		return (0);
	return (1);
}
