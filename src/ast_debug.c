/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:26:13 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/04 12:40:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_debug(const t_node *nd, int i)
{
	printf("===node(%d)===\n", i);
	printf(" ptr    = %p\n", nd);
	printf(" tp     = %d\n", nd->tp);
	printf(" parent = %p\n", nd->parent);
	printf(" left   = %p\n", nd->left);
	printf(" right  = %p\n", nd->right);

	if (nd->left)
		ast_debug(nd->left, ++i);
	if (nd->right)
		ast_debug(nd->right, ++i);
}
