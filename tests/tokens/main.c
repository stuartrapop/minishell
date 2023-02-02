/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:36:29 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 15:03:22 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static const char	*_tp2str(t_toktype tp)
{
	switch (tp)
	{
	case 0:
		return "tok_var";
	case 1:
		return "tok_infile";
	case 2:
		return "tok_outfile";
	case 3:
		return "tok_inheredoc";
	case 4:
		return "tok_outappend";
	case 5:
		return "tok_pipe";
	case 6:
		return "tok_lparen";
	case 7:
		return "tok_rparen";
	case 8:
		return "tok_and";
	case 9:
		return "tok_or";
	default:
		assert(0);
	}
}

void	token_debug(const t_token *tok)
{
	printf("%s\n", "===tok_debug===");
	printf(" tp = %s\n", _tp2str(tok->tp));
	printf(" data = '%s'\n", tok->data);
}

int	main(void)
{
	t_token	tok;
	char	*s;

	s = "(abcd && \"efgh $hey\") || (ijkl && 'mnop $var')";

	while (s && *s)
	{
		ft_memset(&tok, 0, sizeof(t_token));
		s = tokenize(s, &tok);
		token_debug(&tok);
		token_fini(&tok);
	}

	return 0;
}
