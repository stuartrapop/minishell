/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 21:13:45 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_exec(t_node *root)
{
	if (!ast_check(root))
	{
		node_del(&root);
		return (error(0, "syntax"));
	}
	/* ast_debug(root, 0); */
	exec(root);
	node_del(&root);
	return (1);
}

static int	_interp(void)
{
	t_token	tok;
	t_node	*root;
	t_node	*nd;

	root = node_new(0);
	if (!root)
		return (enomem());
	nd = root;
	while (*g_shell->_ptr)
	{
		ft_memset(&tok, 0, sizeof(t_token));
		g_shell->_ptr = tokenize(g_shell->_ptr, &tok);
		if (tok.tp == tok_semicolon)
			break ;
		else if (tok.tp == tok_ampersand)
		{
			error(0, "syntax");
			return (token_fini(&tok) + node_del(&root));
		}
		if (!parse(&tok, &nd, &root))
			return (token_fini(&tok) + node_del(&root));
		token_fini(&tok);
	}
	return (_exec(root));
}

//	returned value is ignored

int	interp(const char *s)
{
	assert(g_shell->_input == 0);
	g_shell->_input = (char *) s;
	g_shell->_ptr = (char *) s;
	while (*g_shell->_ptr)
	{
		if (!_interp())
			break ;
		if (g_shell->_path)
			ft_del_arr(&g_shell->_path);
	}
	shell_reset(g_shell);
	return (1);
}
