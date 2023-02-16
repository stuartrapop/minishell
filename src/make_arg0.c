/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arg0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:12:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/15 16:34:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	1) remove leading backslash
 *	2) variables etc (todo)
 */

char	*make_arg0(t_cmd *cmd)
{
	char	**arg0;

	arg0 = ft_arr_get(&cmd->args, 0);
	if (!arg0)
		return (0);
	if (cmd->_arg0_made)
		return (*arg0);
	unbs(arg0);
	cmd->_arg0_made = 1;
	return (*arg0);
}
