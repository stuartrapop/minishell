/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:01:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 17:26:12 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*_next_node(const t_node *nd)
{
	assert(nd->parent);
	while (nd->parent)
	{
		nd = nd->parent;
		if (!nd->right)
			break ;
	}
	return ((t_node *) nd);
}

//	turn cmd-node into and/or-node

static int	_promote(t_node **nd, t_token *tok, t_node **root)
{
	t_node	*nd2;

	assert(tok->tp == tok_and || tok->tp == tok_or);
	nd2 = node_new((*nd)->parent);
	if (!nd2)
		return (parse_error(0, "nomem", nd));
	if (tok->tp == tok_and)
		nd2->tp = nd_and;
	else
		nd2->tp = nd_or;
	nd2->left = *nd;
	if ((*nd)->parent)
	{
		if ((*nd)->parent->left == *nd)
			(*nd)->parent->left = nd2;
		else
			(*nd)->parent->right = nd2;
	}
	(*nd)->parent = nd2;
	if (*root == *nd)
		*root = nd2;
	return (1);
}

int	parse_cmd(t_node **nd, t_token *tok, t_node **root)
{
	assert((*nd)->tp == nd_cmd);
	if (tok->tp <= 5)
	{
		if (!cmdline_add((*nd)->cmdline, tok))
			return (parse_error(0, "syntax", nd));
	}
	else if (tok->tp == tok_rparen)
	{
		if (!(*nd)->parent || !cmd_valid(cmdline_cmd((*nd)->cmdline)))
			return (parse_error(0, "syntax", nd));
		*nd = _next_node(*nd);
		;
	}
	else if (tok->tp == tok_and || tok->tp == tok_or)
	{
		if (!cmd_valid(cmdline_cmd((*nd)->cmdline)))
			return (parse_error(0, "syntax", nd));
		return (_promote(nd, tok, root));
	}
	else
		return (parse_error(0, "syntax", nd));
	return (1);
}
