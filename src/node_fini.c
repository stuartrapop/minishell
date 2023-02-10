/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_fini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:32:48 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 21:44:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_node_fini(t_node *nd)
{
	if (nd->tp == nd_cmd)
	{
		if (nd->cmdgrp)
		{
			cmdgrp_fini(nd->cmdgrp);
			nd->cmdgrp = 0;
		}
	}
	return (0);
}

int	node_fini(t_node *nd)
{
	if (nd->left)
		node_fini(nd->left);
	if (nd->right)
		node_fini(nd->right);
	return (_node_fini(nd));
}
