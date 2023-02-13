/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:25:48 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 02:04:17 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_redir_fini(t_redir *redir)
{
	if (redir->str)
		ft_del(&redir->str);
}

void	redir_del(void *redirect)
{
	t_redir	**redir;

	redir = redirect;
	assert(*redir);
	_redir_fini(*redir);
	ft_free(*redir);
	*redir = 0;
}
