/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:46:32 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/03 10:56:56 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_cmdline_add_pipe(t_cmdline *cl)
{
	t_cmd	*cmd;

	if (cl->cmds.nelem == 0)
		return (0);
	else
	{
		cmd = *(t_cmd **) ft_arr_get(&cl->cmds, cl->cmds.nelem - 1);
		if (cmd->expect || cmd->args.nelem == 0)
			return (0);
	}
	cmd = cmd_new();
	if (!cmd)
		return (error(0, "nomem"));
	if (!ft_arr_append(&cl->cmds, cmd, 0))
		return (error(0, "nomem") + cmd_del(&cmd));
	return (1);
}

static int	_cmdline_add_var(t_cmdline *cl, char *var)
{
	t_cmd	*cmd;

	cmd = cmdline_cmd(cl);
	if (!cmd)
		return (0);
	if (cmd->expect == 0 && !ft_arr_append(&cmd->args, var, 0))
		return (error(0, "nomem"));
	if (cmd->expect == tok_infile && !ft_arr_append(&cmd->inputs, var, 0))
		return (error(0, "nomem"));
	if (cmd->expect == tok_outfile && !ft_arr_append(&cmd->outputs, var, 0))
		return (error(0, "nomem"));
	if (cmd->expect == tok_inheredoc && !ft_arr_append(&cmd->heredocs, var, 0))
		return (error(0, "nomem"));
	if (cmd->expect == tok_outappend && !ft_arr_append(&cmd->appends, var, 0))
		return (error(0, "nomem"));
	cmd->expect = 0;
	return (1);
}

static int	_cmdline_add_chevron(t_cmdline *cl, t_toktype tp)
{
	t_cmd	*cmd;

	assert(tp >= 1 && tp <= 4);
	cmd = cmdline_cmd(cl);
	if (!cmd || cmd->expect)
		return (0);
	cmd->expect = tp;
	return (1);
}

int	cmdline_add(t_cmdline *cl, t_token *tok)
{
	assert(tok->tp <= 5);
	if (tok->tp == tok_pipe)
		return (_cmdline_add_pipe(cl));
	if (tok->tp == tok_var)
		return (_cmdline_add_var(cl, tok->data));
	return (_cmdline_add_chevron(cl, tok->tp));
}
