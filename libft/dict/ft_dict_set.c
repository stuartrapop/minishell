/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 03:13:16 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_p.h"

typedef struct s_params
{
	char	*k;
	void	*v;
	void	**b;
}	t_params;

static int	_ft_dict_set1(t_dict **d, t_params *parms, size_t h)
{
	t_dictnode	*nd;

	if (!ft_dictnode_new(&nd, parms->k, parms->v))
		return (0);
	if (ft_btree_ins(d, h, nd) < 1)
	{
		ft_dictnode_del(&nd);
		return (0);
	}
	if (parms->b)
		*parms->b = parms->v;
	return (1);
}

static int	_ft_dict_set2(t_dictnode *nd, char *k, void *v, void **b)
{
	t_dictnode	*last;

	last = 0;
	while (nd)
	{
		if (*nd->key == *k && !ft_strcmp(nd->key, k))
			break ;
		last = nd;
		nd = nd->next;
	}
	if (!nd)
	{
		if (!ft_dictnode_new(&nd, k, v))
			return (0);
		last->next = nd;
		if (b)
			*b = v;
		return (1);
	}
	if (b)
		*b = nd->val;
	nd->val = v;
	return (1);
}

int	ft_dict_set(t_dict **d, const char *key, void *val, void **back)
{
	t_params	params;
	size_t		h;
	t_dictnode	*nd;

	if (!*key)
		return (0);
	h = ft_dictnode_hash(key);
	nd = ft_btree_get(*d, h);
	if (!nd)
	{
		params.k = (char *) key;
		params.v = val;
		params.b = back;
		if (!_ft_dict_set1(d, &params, h))
			return (0);
	}
	else
	{
		if (!_ft_dict_set2(nd, (char *) key, val, back))
			return (0);
	}
	return (1);
}
