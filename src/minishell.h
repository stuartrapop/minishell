/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/02 15:25:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <ft_arr.h>
# include <ft_getnext.h>
# include <ft_printf.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <errno.h>
# include <stdio.h>
# include <signal.h>

# define PS1	">>> "

/*
 *	lexer
 */

typedef enum e_toktype
{
	tok_var = 0,
	tok_infile,
	tok_outfile,
	tok_inheredoc,
	tok_outappend,
	tok_pipe,
	tok_lparen,
	tok_rparen,
	tok_and,
	tok_or
}	t_toktype;

typedef struct s_token
{
	t_toktype	tp;
	char		*data;
}	t_token;

/*
 *	syntax tree
 */

typedef enum e_ndtype
{
	nd_cmd = 0,
	nd_and,
	nd_or
}	t_ndtype;

typedef struct s_node	t_node;

typedef struct s_cmdline t_cmdline;

struct s_node
{
	t_ndtype	tp;
	t_node		*parent;
	t_node		*left;
	t_node		*right;
	t_cmdline	*cmdline;
};

/*
 *	...
 */

typedef enum e_opt
{
	o_none = 0,
	o_infile = 1 << 0,
	o_inheredoc = 1 << 1,
	o_outfile = 1 << 2,
	o_outappend = 1 << 3
}	t_opt;

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char	*cmd;
	char	**args;
	char	**env;
	t_arr	command_tokens;
	t_arr 	heredoc;
	t_arr	input;
	t_arr	output;
	t_arr 	append;
	int 	_io[2];
};

struct s_cmdline
{
	t_arr	cmds;
	int		_pipes_in[2];
	int		_pipes_out[2];
};

int		cmd_fini(t_cmd *cl);
int		cmd_init(t_cmd *cl);
int		comp_hd(const char *line, const char *hd);
int		error(const char *title, const char *msg);
int		exec_cmd(t_cmd *cmd, char *env[]);
int		install_sighandler(void);
int		interp(const char *line, char *env[]);
int		node_fini(t_node *nd);
int		open_file_heredoc(const char *eof);
int		open_file_ro(const char *path);
int		open_file_wa(const char *path);
int		open_file_wo(const char *path);
int		root_node_fini(t_node *nd);
int		skip_spaces(const char **s);
int		token_fini(t_token *tok);
char	*tokenize(const char *s, t_token *tok);
char	*tokenize_var(const char *s, t_token *tok);

#endif
