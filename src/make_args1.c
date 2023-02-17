/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:47:06 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/17 12:18:46 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	treat_quotes(char c, t_scan *scan)
{
	if (c == '\'' && !scan->within_double_quotes)
	{
		scan->within_single_quotes = !scan->within_single_quotes;
		return (1);
	}
	else if (c == '\"' && !scan->within_single_quotes)
	{
		scan->within_double_quotes = !scan->within_double_quotes;
		return (1);
	}
	return (0);
}

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

void	split_full_command(char **command_string, t_arr *args)
{
	char	*tmp;
	t_scan	scan;
	char	*new_arg;

	scan.within_double_quotes = 0;
	scan.within_single_quotes = 0;
	ft_arr_fini(args, ft_free);
	ft_arr_init(args, 1, sizeof(char *));
	tmp = *command_string;
	ft_printf("full command: %s\n", tmp);
	while (*tmp)
	{
		if (ft_isspace(*tmp))
			tmp++;
		else
		{
			new_arg = get_cmd_arg(&tmp, &scan);
			ft_arr_append(args, &new_arg, 0);
		}
	}
	return ;
}

static char	*add_env_var(t_arr *new_string, char **str)
{
	char	*var_name;
	int		i;
	char	*env_variable;

	i = 1;
	while ((*str)[i] && !ft_strchr("\"|<> \'|<>()&", (*str)[i]))
		i++;
	var_name = ft_malloc(sizeof(char) * (i + 1));
	var_name = ft_strncpy(var_name, (*str) + 1, i - 1);
	var_name[i - 1] = '\0';
	*str += i;
	env_variable = ft_env_var(var_name, (char **)g_shell->env.data);
	ft_free(var_name);
	if (!env_variable)
		return (NULL);
	while (*env_variable)
	{
		ft_arr_append(new_string, env_variable, 0);
		env_variable++;
	}
	return (env_variable);
}

void	add_arg_to_full_command(t_arr *new_string, char *str)
{
	char	*tmp;
	t_scan	scan;

	scan.within_single_quotes = 0;
	scan.within_double_quotes = 0;
	tmp = str;
	while (*tmp)
	{
		treat_quotes(*tmp, &scan);
		if (*tmp == '$' && !scan.within_single_quotes)
		{
			add_env_var(new_string, &tmp);
			continue ;
		}
		ft_arr_append(new_string, tmp, 0);
		tmp++;
	}
}