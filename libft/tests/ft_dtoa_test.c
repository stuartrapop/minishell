/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:23:13 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 19:16:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_dtoa_test(void)
{
	char	buf[64];

	//printf("%s\n", ft_dtoa(2.39999, 5, buf));

#if 1
	assert(!ft_strcmp(ft_dtoa(2.39999, 1, buf), "2.3"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 2, buf), "2.39"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 3, buf), "2.399"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 4, buf), "2.3999"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 5, buf), "2.39999"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 6, buf), "2.399990"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 7, buf), "2.3999900"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 8, buf), "2.39999000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 9, buf), "2.399990000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 10, buf), "2.3999900000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 11, buf), "2.39999000000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 12, buf), "2.399990000000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 13, buf), "2.3999900000000"));
	assert(!ft_strcmp(ft_dtoa(2.39999, 14, buf), "2.39999000000000"));
	/* assert(!ft_strcmp(ft_dtoa(2.39999, 15, buf), "2.399990000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(2.39999, 16, buf), "2.3999900000000000")); */

	assert(!ft_strcmp(ft_dtoa(2.3, 1, buf), "2.3"));
	assert(!ft_strcmp(ft_dtoa(2.3, 2, buf), "2.30"));
	assert(!ft_strcmp(ft_dtoa(2.3, 3, buf), "2.300"));
	assert(!ft_strcmp(ft_dtoa(2.3, 4, buf), "2.3000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 5, buf), "2.30000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 6, buf), "2.300000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 7, buf), "2.3000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 8, buf), "2.30000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 9, buf), "2.300000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 10, buf), "2.3000000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 11, buf), "2.30000000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 12, buf), "2.300000000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 13, buf), "2.3000000000000"));
	assert(!ft_strcmp(ft_dtoa(2.3, 14, buf), "2.30000000000000"));
	/* assert(!ft_strcmp(ft_dtoa(2.3, 15, buf), "2.300000000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(2.3, 16, buf), "2.3000000000000000")); */

	assert(!ft_strcmp(ft_dtoa(0.1, 1, buf), "0.1"));
	assert(!ft_strcmp(ft_dtoa(0.1, 2, buf), "0.10"));
	assert(!ft_strcmp(ft_dtoa(0.1, 3, buf), "0.100"));
	assert(!ft_strcmp(ft_dtoa(0.1, 4, buf), "0.1000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 5, buf), "0.10000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 6, buf), "0.100000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 7, buf), "0.1000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 8, buf), "0.10000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 9, buf), "0.100000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 10, buf), "0.1000000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 11, buf), "0.10000000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 12, buf), "0.100000000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 13, buf), "0.1000000000000"));
	assert(!ft_strcmp(ft_dtoa(0.1, 14, buf), "0.10000000000000"));
	/* assert(!ft_strcmp(ft_dtoa(0.1, 15, buf), "0.100000000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(0.1, 16, buf), "0.1000000000000000")); */

	assert(!ft_strcmp(ft_dtoa(0.12, 1, buf), "0.1"));
	assert(!ft_strcmp(ft_dtoa(0.12, 2, buf), "0.12"));
	assert(!ft_strcmp(ft_dtoa(0.12, 3, buf), "0.120"));
	assert(!ft_strcmp(ft_dtoa(0.12, 4, buf), "0.1200"));
	assert(!ft_strcmp(ft_dtoa(0.12, 5, buf), "0.12000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 6, buf), "0.120000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 7, buf), "0.1200000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 8, buf), "0.12000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 9, buf), "0.120000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 10, buf), "0.1200000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 11, buf), "0.12000000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 12, buf), "0.120000000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 13, buf), "0.1200000000000"));
	assert(!ft_strcmp(ft_dtoa(0.12, 14, buf), "0.12000000000000"));
	/* assert(!ft_strcmp(ft_dtoa(0.12, 15, buf), "0.120000000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(0.12, 16, buf), "0.1200000000000000")); */

	assert(!ft_strcmp(ft_dtoa(0.999, 1, buf), "0.9"));
	assert(!ft_strcmp(ft_dtoa(0.999, 2, buf), "0.99"));
	assert(!ft_strcmp(ft_dtoa(0.999, 3, buf), "0.999"));
	assert(!ft_strcmp(ft_dtoa(0.999, 4, buf), "0.9990"));
	assert(!ft_strcmp(ft_dtoa(0.999, 5, buf), "0.99900"));
	assert(!ft_strcmp(ft_dtoa(0.999, 6, buf), "0.999000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 7, buf), "0.9990000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 8, buf), "0.99900000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 9, buf), "0.999000000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 10, buf), "0.9990000000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 11, buf), "0.99900000000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 12, buf), "0.999000000000"));
	assert(!ft_strcmp(ft_dtoa(0.999, 13, buf), "0.9990000000000"));
	/* assert(!ft_strcmp(ft_dtoa(0.999, 14, buf), "0.99900000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(0.999, 15, buf), "0.999000000000000")); */
	/* assert(!ft_strcmp(ft_dtoa(0.999, 16, buf), "0.9990000000000000")); */
#endif
}
