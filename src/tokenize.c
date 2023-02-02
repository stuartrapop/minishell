/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:17:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 14:36:57 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tokspec
{
	char		*str;
	size_t		len;
	t_toktype	tp;
}	t_tokspec;

char	*tokenize(const char *s, t_token *tok)
{
	static const t_tokspec	tokspecs[] = {
		{"&&", 2, tok_and},
		{"<<", 2, tok_outappend},
		{">>", 2, tok_inheredoc},
		{"||", 2, tok_or},
		{"(", 1, tok_lparen},
		{")", 1, tok_rparen},
		{"<", 1, tok_outfile},
		{">", 1, tok_infile},
		{"|", 1, tok_pipe},
		{0}
	};
	t_tokspec	*spec;

	/* printf("tokenize='%s'\n", s); */
	if (!skip_spaces(&s))
		return (0);
	spec = (t_tokspec *) &tokspecs[0];
	while (spec->str)
	{
		if (*s == *spec->str
			&& (spec->len == 1 || !ft_strncmp(s, spec->str, spec->len)))
		{
			tok->tp = spec->tp;
			return ((char *) s + spec->len);
		}
		++spec;
	}
	tok->tp = tok_var;
	return (tokenize_var(s, tok));
}
