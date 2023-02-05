/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 10:49:08 by pmarquis         ###   lausanne.ch       */
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
	tok_input,
	tok_output,
	tok_heredoc,
	tok_append,
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
	nd_undef = 0,
	nd_cmd,
	nd_paren,
	nd_and,
	nd_or
}	t_ndtype;

typedef struct s_node		t_node;

typedef struct s_cmdline	t_cmdline;

struct s_node
{
	int			expect;
	t_ndtype	tp;
	t_node		*parent;
	t_node		*left;
	t_node		*right;
	t_cmdline	*cmdline;
};

/*
 *	commands
 */

typedef struct s_cmd
{
	int		expect;
	t_arr	args;
	t_arr	inputs;
	t_arr	outputs;
	t_arr	heredocs;
	t_arr	appends;
	char	**env;
	int		_io[2];
}	t_cmd;

struct s_cmdline
{
	t_arr	cmds;
};

int			ast_check(const t_node *nd);
int			cmd_del(t_cmd **cmd);
void		cmd_fini(void *cl);
int			cmd_init(t_cmd *cl);
t_cmd		*cmd_new(void);
int			cmd_valid(const t_cmd *cmd);
int			cmdline_add(t_cmdline *cl, t_token *tok);
t_cmd		*cmdline_cmd(t_cmdline *cl);
int			cmdline_fini(t_cmdline *cl);
int			cmdline_init(t_cmdline *cl);
t_cmdline	*cmdline_new(void);
int			comp_hd(const char *line, const char *hd);
int			error(const char *title, const char *msg);
int			exec_cmd(t_cmd *cmd, char *env[]);
int			install_sighandler(void);
int			interp(const char *line, char *env[]);
int			node_fini(t_node *nd);
t_node		*node_new(t_node *parent);
void		node_remove(t_node *nd, t_node *child, t_node **root);
void		node_subst(t_node *nd, t_node *nd2, int leftside, t_node **root);
int			open_file_heredoc(const char *eof);
int			open_file_ro(const char *path);
int			open_file_wa(const char *path);
int			open_file_wo(const char *path);
int			parse(t_token *tok, t_node **nd, t_node **root);
int			parse_cmd(t_node **nd, t_token *tok, t_node **root);
int			parse_error(const char *title, const char *msg, t_node **nd);
int			parse_logop(t_node **nd, t_token *tok, t_node **root);
int			parse_paren(t_node **nd, t_token *tok, t_node **root);
int			parse_undef(t_node **nd, t_token *tok);
int			skip_spaces(const char **s);
int			token_fini(t_token *tok);
char		*tokenize(const char *s, t_token *tok);
char		*tokenize_var(const char *s, t_token *tok);

# ifndef NDEBUG
void		ast_debug(const t_node *nd, int i);
# endif

#endif
