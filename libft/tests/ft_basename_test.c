/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:27:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 22:45:57 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_basename_test(void)
{
	char	buf[128];

/* printf("'%s'\n", ft_basename("abcd///", buf)); */
/* printf("'%s'\n", basename("../..")); */

	assert(!ft_strcmp(ft_basename("", buf), basename("")));
	assert(!ft_strcmp(ft_basename(".", buf), basename(".")));
	assert(!ft_strcmp(ft_basename("/", buf), basename("/")));
	assert(!ft_strcmp(ft_basename("///", buf), basename("///")));
	/* assert(!ft_strcmp(ft_basename("../", buf), basename("../"))); basename() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_basename("./", buf), basename("./"))); basename() CRASHES ON LINUX */
	assert(!ft_strcmp(ft_basename("../..", buf), basename("../..")));
	assert(!ft_strcmp(ft_basename("abcd", buf), basename("abcd")));
	/* assert(!ft_strcmp(ft_basename("abcd/", buf), basename("abcd/"))); basename() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_basename("abcd///", buf), basename("abcd///"))); basename() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_basename("/abcd/", buf), basename("/abcd/"))); basename() CRASHES ON LINUX*/
	assert(!ft_strcmp(ft_basename("/abcd", buf), basename("/abcd")));
	assert(!ft_strcmp(ft_basename("abcd/efgh", buf), basename("abcd/efgh")));
	assert(!ft_strcmp(ft_basename("abcd/efgh/ijkl", buf), basename("abcd/efgh/ijkl")));

}
