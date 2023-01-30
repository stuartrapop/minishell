/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:32:42 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/06 00:01:42 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef PREALLOC

void	ft_free(void *ptr)
{
	(void) ptr;
}

#elif !defined( NMEMLIST )

void	ft_free(void *ptr)
{
	t_memlist	**lst;
	t_memlist	*p;
	t_memlist	*prev;

	if (!ptr)
		return ;
	lst = ft_memlist();
	p = *lst;
	prev = 0;
	while (p)
	{
		if (p->data == ptr)
		{
			ft_sllist_take(lst, p, prev);
			free(p);
			return ;
		}
		prev = p;
		p = p->next;
	}
}

#else

void	ft_free(void *ptr)
{
	free(ptr);
}

#endif
