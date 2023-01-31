/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:04:17 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/31 16:06:56 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_parse {
	int	count;
	int	index;
	int	within_piece;
	int	within_single_quotes;
	int	within_double_quotes;
}	t_parse;

int	is_sep(char c, t_parse parse)
{
	if (ft_strchr(" |<>()&", c) \
	&& (!parse.within_single_quotes && !parse.within_double_quotes))
		return (1);
	return (0);
}

int	treat_quotes(char c, t_parse *parse)
{
	if (c == '\'' && !parse->within_double_quotes) 
	{
		parse->within_single_quotes = !parse->within_single_quotes;
		return (1);
	}
	if (c == '\"' && !parse->within_single_quotes) 
	{
		parse->within_double_quotes = !parse->within_double_quotes;
		return (1);
	}
	return (0);
}

static char	*_tokenize_var(const char *s, t_token *tok)
{
	const char	*start = s;
	t_parse 	parse;

	ft_memset(&parse, 0, sizeof(parse));
	// printf("_tokenize_var=%s\n", s);
	while (*s && !is_sep(*s, parse))
	{
		treat_quotes(*s, &parse);
		++s;
	}
	tok->data = ft_strndup(start, s - start );
	printf("value:%s\n", tok->data);
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
	return (_tokenize_var(s, tok));
}
// static char	*_tokenize_var(const char *s, t_token *tok)
// {
// 	const char	*start = s;

// 	// printf("_tokenize_var=%s\n", s); 
// 	while (*s && !ft_isspace(*s))
// 		++s;
// 	tok->data = ft_strndup(start, s - start + 1);
// 	if (!tok->data)
// 	{
// 		error("ft_strndup", "nomem");
// 		return (0);
// 	}
// 	return ((char *) s);
// }

// char	*tokenize_var(const char *s, t_token *tok)
// {
// 	/* printf("tokenize_var=%s\n", s); */
// 	if (!skip_spaces(&s))
// 	{
// 		token_fini(tok);
// 		return (0);
// 	}
// 	if (*s == '\'')
// 		return (tokenize_squote(s + 1, tok));
// 	else if (*s == '\"')
// 		return (tokenize_dquote(s + 1, tok));
// 	return (_tokenize_var(s, tok));
// }
