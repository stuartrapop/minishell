/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 01:05:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_exec_cmd(t_cmd *cmd, char *env[])
{
	/* if (cmd->stdin_opt == 1) */
	/* 	cmd->io[0] = open_file_ro(cmd->infile); */
	/* else if (cmd->stdin_opt == 2) */
	/* 	cmd->io[0] = open_file_heredoc(cmd->infile); */
	/* if (cmd->stdout_opt == 1) */
	/* 	cmd->io[1] = open_file_wo(cmd->outfile); */
	/* else if (cmd->stdout_opt == 2) */
	/* 	cmd->io[1] = open_file_wa(cmd->outfile); */
	/* else */
	/* { */
	/* 	if (pipe(cmd->pipes1) < 0) */
	/* 		return (error(0, "pipe1")); */
	/* 	cmd->io[1] = cmd->pipes1[1]; */
	/* } */
	/* if (cmd->stderr_opt == 1) */
	/* 	cmd->io[2] = open_file_wo(cmd->errfile); */
	/* else if (cmd->stderr_opt == 2) */
	/* 	cmd->io[2] = open_file_wa(cmd->errfile); */
	/* else */
	/* { */
	/* 	if (pipe(cmd->pipes2) < 0) */
	/* 		return (error(0, "pipes2")); */
	/* 	cmd->io[2] = cmd->pipes2[1]; */
	/* } */
	(void) cmd;
	(void) env;
	return (0);
}

static int	_noexec(t_cmd *cmd)
{
	/* if (cmd->stdin_opt == 1) */
	/* 	close(open_file_ro(cmd->infile)); */
	/* else if (cmd->stdin_opt == 2) */
	/* 	close(open_file_heredoc(cmd->infile)); */
	/* if (cmd->stdout_opt == 1) */
	/* 	close(open_file_wo(cmd->outfile)); */
	/* else if (cmd->stdout_opt == 2) */
	/* 	close(open_file_wa(cmd->outfile)); */
	(void) cmd;
	return (0);
}

int	exec_cmd(t_cmd *cmd, char *env[])
{
	/* printf("exec=%s\n", cmd->outfile); */
	/* if (cmd->cmd) */
	/* 	return (_exec_cmd(cmd, env)); */
	/* else */
	/* 	return (_noexec(cmd)); */
	(void) cmd;
	(void) env;
	return (0);
}
