/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:09:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 14:55:06 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_squote(char **s)
{
	(void) s;
	return (0);
}

static char	*_dquote(char **s)
{
	(void) s;
	return (0);
}

static char	*_expand(char **s)
{
	(void) s;
	return (0);
}

// maybe change name. is used to expand redirections

char	*string(char **s)
{
	if (**s == '\'')
		return (_squote(s));
	if (**s == '\"')
		return (_dquote(s));
	return (_expand(s));
}
