/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:27:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/18 00:07:46 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_dirname_test(void)
{
	char	buf[128];

/* printf("'%s'\n", ft_dirname("/", buf)); */
/* printf("'%s'\n", ft_dirname("///", buf)); */
/* printf("'%s'\n", ft_dirname("../..", buf)); */
/* printf("'%s'\n", ft_dirname("/abcd/", buf)); */
/* printf("'%s'\n", ft_dirname("/abcd", buf)); */
/* printf("'%s'\n", ft_dirname("abcd/efgh", buf)); */
/* printf("'%s'\n", ft_dirname("abcd/efgh/ijkl", buf)); */
/* printf("'%s'\n", dirname("../..")); */

	assert(!ft_strcmp(ft_dirname("", buf), dirname("")));
	assert(!ft_strcmp(ft_dirname(".", buf), dirname(".")));
	/* assert(!ft_strcmp(ft_dirname("/", buf), dirname("/"))); dirname() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_dirname("///", buf), dirname("///"))); */
	assert(!ft_strcmp(ft_dirname("../", buf), dirname("../")));
	assert(!ft_strcmp(ft_dirname("./", buf), dirname("./")));
	/* assert(!ft_strcmp(ft_dirname("../..", buf), dirname("../.."))); dirname() CRASHES ON LINUX*/
	assert(!ft_strcmp(ft_dirname("abcd", buf), dirname("abcd")));
	assert(!ft_strcmp(ft_dirname("abcd/", buf), dirname("abcd/")));
	assert(!ft_strcmp(ft_dirname("abcd///", buf), dirname("abcd///")));
	/* assert(!ft_strcmp(ft_dirname("/abcd/", buf), dirname("/abcd/"))); dirname() CRASHES ON LINUX */
	/* assert(!ft_strcmp(ft_dirname("/abcd", buf), dirname("/abcd"))); dirname() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_dirname("abcd/efgh", buf), dirname("abcd/efgh"))); dirname() CRASHES ON LINUX*/
	/* assert(!ft_strcmp(ft_dirname("abcd/efgh/ijkl", buf), dirname("abcd/efgh/ijkl"))); dirname() CRASHES ON LINUX*/

}
