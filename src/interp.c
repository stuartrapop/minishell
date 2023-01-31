/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/31 16:30:07 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_parse(t_token *tok, t_node *root)
{
	return (1);
}

int	interp(const char *s, char *env[])
{
	t_token	tok;
	t_node	root;

	/* printf("interp=%s\n", s); */
	ft_memset(&tok, 0, sizeof(t_token));
	ft_memset(&root, 0, sizeof(t_node));
	while (1)
	{
		if (!skip_spaces(&s))
			break ;
		// printf("string %s\n", s);
		// tokenize_var(s, &tok);
		// return (1);
		s = tokenize(s, &tok);
		// if (!s)
		// 	return (error("interp", s) + token_fini(&tok) + node_fini(&root));
		// if (!_parse(&tok, &root))
		// 	return (token_fini(&tok) + node_fini(&root));
	}
	/* exec(&node, env); */
	root_node_fini(&root);
	token_fini(&tok);
	return (1);
}
