/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_undef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:59:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/04 12:52:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_undef(t_node **nd, t_token *tok)
{
	t_node	*nd2;

	assert((*nd)->tp == nd_undef);
	if (tok->tp <= 5)
	{
		(*nd)->tp = nd_cmd;
		(*nd)->cmdline = cmdline_new();
		if (!(*nd)->cmdline)
			return (parse_error(0, "nomem", nd));
		if (!cmdline_add((*nd)->cmdline, tok))
			return (parse_error(0, "syntax", nd));
	}
	else if (tok->tp == tok_lparen)
	{
		(*nd)->tp = nd_paren;
		nd2 = node_new(*nd);
		if (!nd2)
			return (parse_error(0, "nomem", nd));
		(*nd)->left = nd2;
		*nd = nd2;
	}
	else
		return (parse_error(0, "syntax", nd));
	return (1);
}
