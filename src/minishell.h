/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/07 05:17:20 by pmarquis         ###   lausanne.ch       */
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
	t_arr	args;
	t_arr	inputs;
	t_arr	outputs;
	t_arr	heredocs;
	t_arr	appends;
	int		_expect;
	int		_io[2];
}	t_cmd;

struct s_cmdline
{
	t_arr	cmds;
};

/*
 *	shell info
 */

typedef struct s_shell
{
	t_arr	env;
	int		retval;
}	t_shell;

/*
 *	functions
 */

int			ast_check(const t_node *nd);
int			builtin_cd(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_echo(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_env(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_exit(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_export(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_pwd(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			builtin_unset(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			cmd_builtin(const char *cmd);
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
int			env_dup(t_arr *env, char *environ[]);
char		*env_get(const t_arr *env, const char *varname);
size_t		env_indexof(const t_arr *env, const char *varname);
int			env_set(t_arr *env, const char *varname, const char *value);
int			error(const char *title, const char *msg);
void		exec(t_node *root, char *env[]);
int			exec_builtin(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
int			exec_cmd(t_cmdline *cl, t_cmd *cmd, t_shell *sh);
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
int			shell_init(t_shell *sh, char *environ[]);
t_shell		*shell_new(char *environ[]);
int			skip_spaces(const char **s);
int			token_fini(t_token *tok);
char		*tokenize(const char *s, t_token *tok);
char		*tokenize_var(const char *s, t_token *tok);

# ifndef NDEBUG
void		ast_debug(const t_node *nd, int i);
# endif

#endif
