/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:04:17 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/01 14:11:20 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_scan {
	int	count;
	int	index;
	int	within_piece;
	int	within_single_quotes;
	int	within_double_quotes;
}	t_scan;

int	is_sep(char c, t_scan scan)
{
	if (ft_strchr(" |<>()&", c) \
	&& (!scan.within_single_quotes && !scan.within_double_quotes))
		return (1);
	return (0);
}

int	treat_quotes(char c, t_scan *scan)
{

	if (c == '\'' && !scan->within_double_quotes)
	{
		scan->within_single_quotes = !scan->within_single_quotes;
		return (1);
	}
	if (c == '\"' && !scan->within_single_quotes)
	{
		scan->within_double_quotes = !scan->within_double_quotes;
		return (1);
	}
	return (0);
}

static char	*_tokenize_var(const char *s, t_token *tok)
{
	const char	*start = s;
	t_scan 	scan;

	ft_memset(&scan, 0, sizeof(scan));
	// printf("_tokenize_var=%s\n", s);
	while (*s && !is_sep(*s, scan))
	{
		treat_quotes(*s, &scan);
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
