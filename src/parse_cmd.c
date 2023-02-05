/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:01:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 01:21:39 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*_close_paren(t_node *nd, t_node **root)
{
	t_node	*child;

	assert(nd->parent);
	while (nd->parent)
	{
		child = nd;
		nd = nd->parent;
		if (nd->tp == nd_paren)
		{
			node_remove(nd, child, root);
			nd->left = 0;
			nd->right = 0;
			node_fini(nd);
			return (child);
		}
	}
	return (0);
}

static int	_add_right_node(t_node *p, t_node **nd)
{
	p->right = node_new(p);
	if (!p->right)
		return (parse_error(0, "nomem", nd));
	*nd = p->right;
	return (1);
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
	node_subst(*nd, nd2, 1, root);
	return (_add_right_node(nd2, nd));
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
		*nd = _close_paren(*nd, root);
		if (!*nd)
			return (parse_error(0, "syntax", nd));
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
