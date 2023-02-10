/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_fini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:53:42 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 20:59:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmdgrp_fini(t_cmdgrp *cl)
{
	ft_arr_fini(&cl->cmds, &cmd_fini);
	return (0);
}
