/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:53:46 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/21 11:08:06 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_cmd_arg(char **str, t_scan *scan)
{
	int		i;
	t_arr	new_arg;
	char	*ret;

	ft_arr_init(&new_arg, 4, sizeof(char));
	i = 0;
	while ((*str)[i])
	{
		if (treat_quotes((*str)[i], scan))
			;
		else if (ft_strchr("|<> &", (*str)[i]) && !scan->within_double_quotes \
			&& !scan->within_single_quotes)
			break ;
		else
			ft_arr_append(&new_arg, &(*str)[i], 0);
		i++;
	}
	*str += i;
	ret = ft_strdup((char *)new_arg.data);
	ft_arr_fini(&new_arg, ft_free);
	return (ret);
}

char	*make_arg0(t_cmd *cmd)
{
	char	*full_command;
	t_scan	scan;
	char	*first_arg;

	scan.within_double_quotes = 0;
	scan.within_single_quotes = 0;
	full_command = make_full_command(&cmd->args);
	if (!*full_command)
		return (NULL);
	while (ft_isspace(*full_command))
		full_command++;
	first_arg = get_cmd_arg(&full_command, &scan);
	unbs(&first_arg);
	if (!first_arg || *first_arg == '\0')
		return (NULL);
	if (cmd->_arg0_made)
		return (first_arg);
	unbs(&first_arg);
	cmd->_arg0_made = 1;
	return (first_arg);
}
