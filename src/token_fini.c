/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_fini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:26 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/17 15:42:46 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_fini(t_token *tok)
{
	if (tok->data)
	{
		if (tok->tp == tok_infile || tok->tp == tok_outfile
			|| tok->tp == tok_inheredoc || tok->tp == tok_outappend)
			ft_del(&tok->data);
	}
	return (0);
}
