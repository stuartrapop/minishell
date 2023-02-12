/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:09:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 21:27:56 by pmarquis         ###   lausanne.ch       */
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

char	*string(char **s)
{
	if (**s == '\'')
		return (_squote(s));
	if (**s == '\"')
		return (_dquote(s));
	return (*s);
}
