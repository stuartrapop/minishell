/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:42:04 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 00:52:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	splash(void)
{
	if (!abspath_find("neofetch"))
	{
		ft_printf("\e[1m");
		interp("uname -a");
		ft_printf("\e[0m");
	}
	else
		interp("neofetch");
}
