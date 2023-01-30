/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:33:13 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include "ft_btree.h"
# include "libft.h"

/*
 *	Public
 */

typedef t_btree	t_dict;

void		ft_dict_del(t_dict **d, t_fn1 fn);
void		*ft_dict_get(const t_dict *d, const char *key);
int			ft_dict_set(t_dict **d, const char *k, void *v, void **b);
void		ft_dict_trav(t_dict *d, t_fn1 fn);
void		ft_dict_trav2(t_dict *d, t_fn2 fn, void *userdata);
void		ft_dict_trav_kv(t_dict *d, t_fn3 fn);
void		ft_dict_trav_kv2(t_dict *d, t_fn4 fn, void *u);
void		*ft_dict_unset(t_dict **d, const char *key);

#endif
