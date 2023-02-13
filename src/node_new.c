/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:59:53 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 19:39:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_node_init(t_node *nd, const t_node *parent)
{
	if (parent)
		nd->parent = (t_node *) parent;
}

t_node	*node_new(const t_node *parent)
{
	t_node	*nd;

	nd = ft_calloc(1, sizeof(t_node));
	if (!nd)
		return (0);
	_node_init(nd, parent);
	return (nd);
}
