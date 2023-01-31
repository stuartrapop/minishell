/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:17:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/31 16:28:35 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tokspec
{
	char		*str;
	size_t		len;
	t_toktype	tp;
	char		*(*f)(const char *, t_token *);
}	t_tokspec;

char	*tokenize(const char *s, t_token *tok)
{
	static const t_tokspec	tokspecs[] = {
		{"&&", 2, tok_and, 0},
		{"<<", 2, tok_outappend, 0},
		{">>", 2, tok_inheredoc, 0},
		{"||", 2, tok_or, 0},
		{"(", 1, tok_lparen, 0},
		{")", 1, tok_rparen, 0},
		{"<", 1, tok_outfile, 0},
		{">", 1, tok_infile, 0},
		{"|", 1, tok_pipe, 0},
		{0, 0, tok_string, 0}
	};
	t_tokspec	*spec;

	assert(*s);
	/* printf("tokenize=%s\n", s); */
	/* if (!skip_spaces(&s)) */
	/* 	return (0); */
	spec = (t_tokspec *) &tokspecs[0];
	while (spec->str)
	{
		if (*s == *spec->str
			&& (spec->len == 1 || !ft_strncmp(s, spec->str, spec->len)))
		{
			tok->tp = spec->tp;
			if (spec->f)
				return ((*spec->f)(s + spec->len, tok));
			return ((char *) s + spec->len);
		}
		++spec;
	}
	tok->tp = tok_var;
	return (tokenize_var(s, tok));
}
