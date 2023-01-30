/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_p.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:55:49 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/05 22:57:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_P_H
# define FT_DICT_P_H

# include "ft_dict.h"

/*
 *	PRIVATE STUFF
 */

typedef struct s_dictnode
{
	struct s_dictnode	*next;
	void				*val;
	char				key[];
}	t_dictnode;

size_t		ft_dictnode_hash(const void *k);
void		*ft_dictnode_new(t_dictnode **nd, const char *k, void *v);
void		ft_dictnode_del(t_dictnode **nd);
void		ft_dictnode_list_del(t_dictnode *nd);

#endif
