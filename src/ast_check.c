/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:46:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 10:48:51 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ast_check(const t_node *nd)
{
	if (nd->tp == nd_paren)
		return (0);
	if (nd->left && !ast_check(nd->left))
		return (0);
	if (nd->right && !ast_check(nd->right))
		return (0);
	return (1);
}
