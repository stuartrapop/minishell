/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_check_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:45:55 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 09:46:00 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_utf8_check_test(void)
{
	assert(ft_strlen("é") == 2 && ft_utf8_check("é") == 1);
	assert(ft_strlen("Ā") == 2 && ft_utf8_check("Ā") == 1);
	assert(ft_strlen("\xe0\xb8\x81") == 3 && ft_utf8_check("\xe0\xb8\x81") == 1);
}
