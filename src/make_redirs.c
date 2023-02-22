/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:10:14 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/22 11:42:55 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*clean_redirect(char **str)
{
	int		i;
	t_arr	new_arg;
	char	*ret;
	t_scan	scan;

	scan.within_double_quotes = 0;
	scan.within_single_quotes = 0;
	ft_arr_init(&new_arg, 4, sizeof(char));
	i = 0;
	while ((*str)[i])
	{
		if (treat_quotes((*str)[i], &scan))
			;
		else
			ft_arr_append(&new_arg, &(*str)[i], 0);
		i++;
	}
	ret = ft_strdup((char *)new_arg.data);
	ft_arr_fini(&new_arg, ft_free);
	ft_free(*str);
	return (ret);
}

static char	*exp_redir_str(char *fn)
{
	t_arr		new_string;
	char		*exp_str;

	ft_arr_init(&new_string, 128, sizeof(char));
	if (!fn)
		return (NULL);
	add_arg_to_full_command(&new_string, fn);
	exp_str = ft_strdup((char *)new_string.data);
	ft_arr_fini(&new_string, ft_free);
	return (exp_str);
}

int	expand_redirs(t_cmd *cmd)
{
	size_t	i;
	char	*expand_str;
	char	*tmp;

	i = 0;
	while (i < cmd->redirs.nelem)
	{
		if (((t_redir *)cmd->redirs.data)[i].tp != redir_heredoc)
		{
			expand_str = exp_redir_str(((t_redir *)cmd->redirs.data)[i].str);
			tmp = ((t_redir *)cmd->redirs.data)[i].str;
			((t_redir *)cmd->redirs.data)[i].str = expand_str;
		}
		ft_free(tmp);
		i++;
	}
	return (0);
}
