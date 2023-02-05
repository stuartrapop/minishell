/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_logop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:42:16 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 01:56:34 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_logop(t_node **nd, t_token *tok, t_node **root)
{
	t_node	*nd2;

	assert((*nd)->tp == nd_and || (*nd)->tp == nd_or);
	if (tok->tp != tok_and && tok->tp != tok_or)
		return (parse_error(0, "syntax", nd));
	nd2 = node_new((*nd)->parent);
	if (!nd2)
		return (parse_error(0, "nomem", nd));
	if (tok->tp == tok_and)
		nd2->tp = nd_and;
	else
		nd2->tp = nd_or;
	node_subst(*nd, nd2, 1, root);
	nd2 = node_new(nd2);
	if (!nd2)
		return (parse_error(0, "nomem", nd));
	nd2->parent->right = nd2;
	*nd = nd2;
	return (1);
}
