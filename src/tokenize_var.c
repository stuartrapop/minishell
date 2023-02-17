/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:04:17 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 12:23:30 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_sep(char c, const t_scan *scan)
{
	if (ft_strchr(" |<>()&;", c)
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

	assert(*s);
	tok->tp = tok_var;
	ft_memset(&scan, 0, sizeof(scan));
	while (*s && !_is_sep(*s, &scan))
	{
		_treat_quotes(*s, &scan);
		++s;
	}
	tok->data = ft_strndup(start, s - start);
	if (!tok->data)
		enomem();
	return ((char *) s);
}
