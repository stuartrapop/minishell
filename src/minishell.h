/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 03:50:57 by pmarquis         ###   lausanne.ch       */
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
# include <sys/wait.h>

# define PS1	"minishell--> "

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

typedef struct s_cmdgrp		t_cmdgrp;

struct s_node
{
	t_ndtype	tp;
	t_node		*parent;
	t_node		*left;
	t_node		*right;
	t_cmdgrp	*cmdgrp;
};

/*
 *	redirections
 */

typedef enum e_redirtp
{
	redir_undef = 0,
	redir_input,
	redir_output,
	redir_heredoc,
	redir_append
}	t_redirtp;

typedef struct s_redir
{
	t_redirtp	tp;
	char		*str;
}	t_redir;

/*
 *	commands
 */

typedef struct s_cmd
{
	t_arr	args;
	t_arr	redirs;
	int		_expect;
	int		_input_or_heredoc;
	int		_output_or_append;
	int		_input_fd;
	int		_heredoc_fd;
	int		_output_fd;
	int		_append_fd;
	int		_pipe[2];
	int		_io[2];
	int		_pid;
}	t_cmd;

struct s_cmdgrp
{
	t_arr	cmds;
};

/*
 *	shell info
 */

typedef struct s_shell
{
	t_arr				env;
	int					retval;
	struct sigaction	*orig_sigint;
	t_cmdgrp			*_cmdgrp;
	char				**_path;
}	t_shell;

extern
t_shell * g_shell;

/*
 *	functions
 */

int			ast_check(const t_node *nd);
int			builtin_cd(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_echo(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_env(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_exit(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_export(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_pwd(t_cmdgrp *cl, t_cmd *cmd);
int			builtin_unset(t_cmdgrp *cl, t_cmd *cmd);
int			cmd_builtin(const char *cmd);
int			cmd_fildes(t_cmdgrp *cgrp, t_cmd *cmd, size_t num);
void		cmd_fini(void *cl);
int			cmd_link(t_cmd *cmd);
t_cmd		*cmd_new(void);
int			cmd_redir(t_cmd *cmd);
int			cmd_redir_append(t_cmd *cmd, t_redir *redir);
int			cmd_redir_input(t_cmd *cmd, t_redir *redir);
int			cmd_redir_output(t_cmd *cmd, t_redir *redir);
int			cmd_valid(const t_cmd *cmd);
int			cmdgrp_add(t_cmdgrp *cl, t_token *tok);
t_cmd		*cmdgrp_cmd(t_cmdgrp *cl);
int			cmdgrp_fini(t_cmdgrp *cl);
t_cmdgrp	*cmdgrp_new(void);
int			enomem(void);
char		*env_get(const t_arr *env, const char *varname);
size_t		env_indexof(const t_arr *env, const char *varname);
int			env_set(t_arr *env, const char *varname, const char *value);
int			env_unset(t_arr *env, const char *varname);
int			error(const char *title, const char *msg);
void		exec(t_node *root);
int			exec_builtin(t_cmdgrp *cl, t_cmd *cmd);
int			exec_cmd(t_cmdgrp *cl, t_cmd *cmd, size_t num);
int			exec_simple_builtin(t_cmdgrp *cgrp, t_cmd *cmd);
int			fd_close(int *fd);
int			interp(const char *s);
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
int			parse_logop(t_node **nd, t_token *tok, t_node **root);
int			parse_paren(t_node **nd, t_token *tok, t_node **root);
int			parse_undef(t_node **nd, t_token *tok);
char		*ps1(void);
void		redir_fini(void *redir);
t_shell		*shell_new(char *environ[]);
void		shell_reset(t_shell *sh);
int			sighandlers_install(void);
int			sighandlers_remove(void);
int			skip_spaces(const char **s);
int			token_fini(t_token *tok);
char		*tokenize(const char *s, t_token *tok);
char		*tokenize_var(const char *s, t_token *tok);
int			waitpids(const t_arr *cmds);

# ifndef NDEBUG

void		ast_debug(const t_node *nd, int i);

# endif

#endif
