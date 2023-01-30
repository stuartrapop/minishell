/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:04:17 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/18 00:51:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_tokenize_var(const char *s, t_token *tok)
{
	const char	*start = s;

	/* printf("_tokenize_var=%s\n", s); */
	while (*s && !ft_isspace(*s))
		++s;
	tok->data = ft_strndup(start, s - start + 1);
	if (!tok->data)
	{
		error("ft_strndup", "nomem");
		return (0);
	}
	return ((char *) s);
}

char	*tokenize_var(const char *s, t_token *tok)
{
	/* printf("tokenize_var=%s\n", s); */
	if (!skip_spaces(&s))
	{
		token_fini(tok);
		return (0);
	}
	if (*s == '\'')
		return (tokenize_squote(s + 1, tok));
	else if (*s == '\"')
		return (tokenize_dquote(s + 1, tok));
	return (_tokenize_var(s, tok));
}
