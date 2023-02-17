/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 12:16:45 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	expand_arg_wildcards(t_arr *args)
{
	size_t	i;
	char	*s;

	i = 0;
	while (++i < args->nelem)
	{
		s = *(char **) ft_arr_get(args, i);
		if (*s == '*' && !ft_strcmp(s, "*"))
		{
			if (!wildcard(args, i))
				return (0);
			i = -1;
		}
	}
	return (1);
}

char	*make_full_command(t_arr *args)
{
	t_arr		new_string;
	size_t		i;
	char		*tmp;
	char		*full_command;

	ft_arr_init(&new_string, 128, sizeof(char));
	i = 0;
	while (i < args->nelem)
	{
		tmp = ((char **)args->data)[i];
		ft_printf("arg %s\n", tmp);
		if (!tmp)
			break ;
		add_arg_to_full_command(&new_string, tmp);
		if (i == args->nelem -2)
			ft_arr_append(&new_string, " ", 0);
		i++;
	}
	full_command = ft_strdup((char *)new_string.data);
	ft_arr_fini(&new_string, ft_free);
	return (full_command);
}

int	make_args(t_arr *args)
{
	char		*full_command;

	full_command = make_full_command(args);
	split_full_command(&full_command, args);
	expand_arg_wildcards(args);
	return (1);
}

char	*make_arg0(t_cmd *cmd)
{
	char	*full_command;
	t_scan	scan;
	char	*first_arg;

	scan.within_double_quotes = 0;
	scan.within_single_quotes = 0;
	full_command = make_full_command(&cmd->args);
	ft_printf("full command after make %s\n", full_command);
	if (!*full_command)
		return (NULL);
	while (ft_isspace(*full_command))
		full_command++;
	first_arg = get_cmd_arg(&full_command, &scan);
	ft_printf("first element %s\n", first_arg);
	unbs(&first_arg);
	if (cmd->_arg0_made)
		return (first_arg);
	unbs(&first_arg);
	cmd->_arg0_made = 1;
	return (first_arg);
}
