/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:42:04 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 17:01:07 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	using "uname -a" if neofetch isnt found,
//	but we could go for some ascii art :)

void	splash(void)
{
	char	*p;

	p = abspath_find("neofetch");
	if (!p)
	{
		p = abspath_find("uname");
		if (!p)
			return ;
		ft_free(p);
		ft_printf("\e[1m");
		interp("uname -a");
		ft_printf("\e[0m");
	}
	else
	{
		ft_free(p);
		interp("neofetch");
	}
}
