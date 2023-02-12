/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:46:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 00:39:24 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_reset(t_shell *sh)
{
	if (sh->_path)
		ft_del_arr(&sh->_path);
	assert(sh->cmdgrp == 0);
}