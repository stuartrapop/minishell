/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 01:55:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_exec(t_node *root)
{
	exec(root);
	node_del(&root);
	shell_reset(g_shell);
	return (1);
}

//	returned value is ignored

int	interp(const char *s)
{
	t_token	tok;
	t_node	*root;
	t_node	*nd;

	root = node_new(0);
	if (!root)
		return (enomem());
	nd = root;
	while (s && *s)
	{
		ft_memset(&tok, 0, sizeof(t_token));
		s = tokenize(s, &tok);
		if (!parse(&tok, &nd, &root))
			return (token_fini(&tok) + node_del(&root));
		token_fini(&tok);
	}
	if (!ast_check(root))
	{
		node_del(&root);
		return (error(0, "syntax"));
	}
	/* ast_debug(root, 0); */
	return (_exec(root));
}
