/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:29:33 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 18:03:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ps1(void)
{
	char		*ps1;
	static char	buf[32];

	ps1 = ft_env_var("PS1", g_shell->env.data);
	if (!ps1 || !*ps1 || ft_strisspace(ps1))
	{
		buf[0] = '(';
		ft_itoa(g_shell->retval, &buf[1]);
		ft_strcatchr(buf, ')', 1);
		ft_strcpy(ft_strchr(buf, 0), PS1);
		ps1 = buf;
	}
	return (ps1);
}
