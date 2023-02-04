/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:51:08 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/04 13:00:34 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse(t_token *tok, t_node **nd, t_node **root)
{
	if ((*nd)->tp == nd_undef)
		return (parse_undef(nd, tok));
	else if ((*nd)->tp == nd_cmd)
		return (parse_cmd(nd, tok, root));
	else
		assert(0);
	return (0);
}
