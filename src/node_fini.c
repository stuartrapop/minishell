/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_fini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:32:48 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/26 18:27:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	node_fini(t_node *nd)
{
	/* if (nd->tp == nd_cmd) */
	/* { */
	/* 	if (nd->data) */
	/* 		cmd_fini(nd->data); */
	/* } */
	return (0);
}

int	root_node_fini(t_node *nd)
{
	return (0);
}
