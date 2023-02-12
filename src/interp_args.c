/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:27:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 20:01:39 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	for debugging purposes...

int	interp_args(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**cmds;

	i = -1;
	while (++i < argc)
	{
		cmds = ft_split(argv[i], ';');
		if (!cmds)
			enomem();
		j = -1;
		while (cmds[++j])
			interp(cmds[j]);
		ft_del_arr(&cmds);
	}
	finish(g_shell->retval);
	return (0);
}
