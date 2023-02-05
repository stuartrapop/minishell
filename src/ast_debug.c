/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:26:13 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:20 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*_tp2str(t_ndtype tp)
{
	switch (tp)
	{
	case nd_undef:
		return "nd_undef";
	case nd_cmd:
		return "nd_cmd";
	case nd_paren:
		return "nd_paren";
	case nd_and:
		return "nd_and";
	case nd_or:
		return "nd_or";
	default:
		assert(0);
	}
	return (0);
}

void	ast_debug(const t_node *nd, int i)
{
	printf("===node(lvl:%d)===\n"
	       " ptr    = %p\n"
	       " tp     = %s\n"
	       " parent = %p\n"
	       " left   = %p\n"
	       " right  = %p\n",
		   i, nd, _tp2str(nd->tp), nd->parent, nd->left, nd->right);

	if (nd->left)
		ast_debug(nd->left, i + 1);
	if (nd->right)
		ast_debug(nd->right, i + 1);
}
