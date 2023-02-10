/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_fini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:25:48 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 14:18:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_fini(void *redirect)
{
	t_redir	*redir;

	redir = (t_redir *) redirect;
	redir->tp = redir_undef;
	if (redir->str)
		ft_del(&redir->str);
}
