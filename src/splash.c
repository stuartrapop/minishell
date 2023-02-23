/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:42:04 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 18:05:55 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	using "uname -a" if neofetch isnt found,
//	but we could go for some ascii art :)

void	splash(void)
{
	char	*p;
	char	*uname_command;

	p = abspath_find("neofetch");
	if (!p)
	{
		p = abspath_find("uname");
		if (!p)
			return ;
		ft_free(p);
		ft_printf("\e[1m");
		uname_command = ft_strdup("uname -a");
		interp(uname_command);
		ft_printf("\e[0m");
	}
	else
	{
		ft_free(p);
		interp("neofetch");
	}
}
