/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_fini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:26 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 02:05:41 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	tok->data ownership is transfered to a t_cmd*->something

int	token_fini(t_token *tok)
{
	assert(tok->data == 0);
	if (tok->data)
		ft_del(&tok->data);
	return (0);
}
