/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 15:17:44 by pmarquis         ###   lausanne.ch       */
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

	/* printf("interp='%s'\n", s); */
	ft_memset(&root, 0, sizeof(t_node));
	while (s && *s)
	{
		ft_memset(&tok, 0, sizeof(t_token));
		s = tokenize(s, &tok);
		/* if (!_parse(&tok, &root)) */
		/* 	return (token_fini(&tok) + node_fini(&root)); */
		token_fini(&tok);
	}
	/* exec(&node, env); */
	/* root_node_fini(&root); */
	return (1);
}
