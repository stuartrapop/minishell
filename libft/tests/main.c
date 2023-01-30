/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:36:25 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/30 16:44:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

int main(void)
{
	setlocale(LC_ALL, "C");
	puts("=== startests ===\n");

	/* ft_basename_test(); */
	/* ft_bsort_test(); */
	/* ft_del_test(); */
	/* ft_dirname_test(); */
	/* ft_dtoa_test(); */
	/* ft_memcmp_test(); */
	/* ft_memmove_test(); */
	/* ft_memset_test(); */
	/* ft_memory_test(); */
	/* ft_multovf_test(); */
	/* ft_qsort_test(); */
	/* ft_split_test(); */
	/* ft_startswith_test(); */
	/* ft_strcasecmp_test(); */
	/* ft_strchr_test(); */
	/* ft_strcmp_test(); */
	/* ft_strlen_test(); */
	/* ft_strncasecmp_test(); */
	/* ft_strncmp_test(); */
	/* ft_strncpy_test(); */
	/* ft_strnlen_test(); */
	ft_strspn_test();
	/* ft_utf8_check_test(); */
	/* ft_utf8_len_test(); */

	puts("=== endtests ===\n");
	return (0);
}
