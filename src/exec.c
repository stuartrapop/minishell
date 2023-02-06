/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/06 21:56:28 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*_tp2str(t_ndtype tp)
{
	switch (tp)
	{
	case nd_undef:
		return "nd_undef";
	case nd_cmd:
		return "nd_cmd";
	case nd_paren:
		return "nd_paren";
	case nd_and:
		return "nd_and";
	case nd_or:
		return "nd_or";
	default:
		assert(0);
	}
	return (0);
}

char	*get_full_command(char *str, char *paths[])
{
	int		index;
	char	*test_path;
	char	*tmp;

	index = 0;
	while (paths[index])
	{
		tmp = ft_strjoin(paths[index], "/");
		test_path = ft_strjoin(tmp, str);
		if (access(test_path, X_OK) == 0)
			return (test_path);
		index++;
	}
	return (NULL);
}

int	ft_waitallpids(t_arr *cmds)
{
	int		index;
	t_cmd	*command;
	int		status;
	int		status_code;

	status_code = 0;
	index = 0;
	while (index < ft_arr_len((cmds)))
	{
		command = *(t_cmd **)ft_arr_get((cmds), index);
		waitpid(command, &status, 0);
		if (WIFEXITED(status))
			status_code = WEXITSTATUS(status);
		else
			status_code = 0;
		index++;
	}
	return (status_code);
}

int	exec_cmd(t_cmd *cmds, int idx_cmd, t_minishell *minishell)
{
	char	**cmd_args;
	int		idx_arg;
	char	*full_path;

	printf("command number %d\n", idx_cmd);
	cmd_args = (char **)ft_arr_get(&(cmds[idx_cmd]).args, 0);
	idx_arg = 0;
	full_path = get_full_command(cmd_args[0], minishell->paths);
	printf("first path %s\n", minishell->paths[0]);
	if (!full_path)
		return (127);
	while (idx_arg < ft_arr_len(&((cmds)[idx_cmd].args)))
	{
		printf("arg %d: %s\n", idx_arg + 1, cmd_args[idx_arg]);
		idx_arg++;
	}
	dup2(minishell->tmp_fd, STDIN_FILENO);
	close(minishell->tmp_fd);
	printf("full path %s\n", full_path);
	execve(full_path, &cmd_args[0], minishell->env);
	printf("after exec\n");
}


void	exec_cmd_line(const t_node *nd, t_arr *env)
{
	t_cmd		**commands;
	int			idx_cmd;
	t_minishell	minishell;

	printf("num commands %zu\n", ft_arr_len(&(nd->cmdline->cmds)));
	minishell.env = (char **)ft_arr_get(env, 0);
	printf("num commands  num 2 %zu\n", ft_arr_len(&(nd->cmdline->cmds)));
	minishell.paths = ft_split(ft_env_var("PATH", minishell.env), ':');
	commands = (t_cmd **)ft_arr_get(&(nd->cmdline->cmds), 0);
	if (pipe(minishell._io) == -1)
	{
		exit (error(0, "pipe error"));
	}
	idx_cmd = 0;
	while (idx_cmd < ft_arr_len(&(nd->cmdline->cmds)))
	{
		commands[idx_cmd]->pid = fork();
		if (commands[idx_cmd]->pid == -1)
			exit (error(0, "fork error"));
		if (commands[idx_cmd]->pid == 0)
			exec_cmd(*commands, idx_cmd, &minishell);
		idx_cmd++;
	}
	ft_waitallpids(&(nd->cmdline->cmds));
	printf("after pid waits\n");
}

void	exec(t_node *root, char *environ[])
{
	t_arr	*env;
	t_node	*current;

	//static was not working for me - env was not valid on second pass.
	env = env_dup(environ);
	if (!env)
	{
		error(0, "nomem");
		return ;
	}
	current = root;
	while (current->left)
		current = current->left;
	exec_cmd_line(current, env);
}
