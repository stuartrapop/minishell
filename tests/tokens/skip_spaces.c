/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:28:47 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 14:17:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	skip_spaces(const char **s)
{
	while (**s && ft_isspace(**s))
		++(*s);
	if (!(**s))
		return (0);
	return (1);
}
