/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:59:53 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 19:27:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*node_new(t_node *parent)
{
	t_node	*nd;

	nd = ft_calloc(1, sizeof(t_node));
	if (!nd)
		return (0);
	if (parent)
		nd->parent = parent;
	return (nd);
}
