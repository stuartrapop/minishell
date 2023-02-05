/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:04:17 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 20:49:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_scan
{
	int	count;
	int	index;
	int	within_piece;
	int	within_single_quotes;
	int	within_double_quotes;
}	t_scan;

static int	_is_sep(char c, const t_scan *scan)
{
	if (ft_strchr(" |<>()&", c)
		&& !scan->within_single_quotes && !scan->within_double_quotes)
		return (1);
	return (0);
}

static void	_treat_quotes(char c, t_scan *scan)
{
	if (c == '\'' && !scan->within_double_quotes)
		scan->within_single_quotes = !scan->within_single_quotes;
	else if (c == '\"' && !scan->within_single_quotes)
		scan->within_double_quotes = !scan->within_double_quotes;
}

char	*tokenize_var(const char *s, t_token *tok)
{
	const char	*start = s;
	t_scan		scan;

	if (!skip_spaces(&s))
	{
		token_fini(tok);
		return (0);
	}
	ft_memset(&scan, 0, sizeof(scan));
	while (*s && !_is_sep(*s, &scan))
	{
		_treat_quotes(*s, &scan);
		++s;
	}
	tok->data = ft_strndup(start, s - start);
	if (!tok->data)
	{
		error(0, "nomem");
		return (0);
	}
	return ((char *) s);
}
