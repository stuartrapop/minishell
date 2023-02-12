/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:29:33 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 02:50:34 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ps1(void)
{
	char	*ps1;

	ps1 = ft_env_var("PS1", g_shell->env.data);
	if (!ps1 || !*ps1 || ft_strisspace(ps1))
		ps1 = PS1;
	return (ps1);
}
