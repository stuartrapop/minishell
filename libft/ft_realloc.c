/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:38:23 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:23:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef NMEMLIST

static inline int	__ft_realloc(t_memlist **q, t_memlist *p, size_t sz)
{
	*q = malloc(sizeof(t_memlist) + sz);
	if (!*q)
		return (0);
	(*q)->next = 0;
	(*q)->sz = sz;
	if (sz >= p->sz)
		ft_memcpy((*q)->data, p->data, p->sz);
	else
		ft_memcpy((*q)->data, p->data, sz);
	return (1);
}

static inline void	*_ft_realloc(void *ptr, size_t sz)
{
	t_memlist	**lst;
	t_memlist	*p;
	t_memlist	*prev;
	t_memlist	*q;

	lst = ft_memlist();
	p = *lst;
	prev = 0;
	while (p)
	{
		if (p->data == ptr)
		{
			if (p->sz == sz)
				return (p);
			ft_sllist_take(lst, p, prev);
			if (!__ft_realloc(&q, p, sz))
				return (0);
			ft_sllist_push(lst, q);
			free(p);
			return (q->data);
		}
		prev = p;
		p = p->next;
	}
	return (0);
}

void	*ft_realloc(void *ptr, size_t sz)
{
	if (!ptr)
	{
		if (sz)
			return (ft_malloc(sz));
		return (0);
	}
	if (!sz)
	{
		ft_free(ptr);
		return (0);
	}
	return (_ft_realloc(ptr, sz));
}

#else // def NMEMLIST

static inline void	*_ft_realloc(void *ptr, size_t sz, size_t psz)
{
	void	*q;

	q = malloc(sz);
	if (!q)
		return (0);
	if (sz >= psz)
		ft_memcpy(q, ptr, psz);
	else
		ft_memcpy(q, ptr, sz);
	free(ptr);
	return (q);
}

void	*ft_realloc(void *ptr, size_t sz, size_t psz)
{
	if (!ptr)
	{
		if (sz)
			return (malloc(sz));
		return (0);
	}
	if (!sz)
	{
		free(ptr);
		return (0);
	}
	return (_ft_realloc(ptr, sz, psz));
}

#endif // ndef NMEMLIST
