/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:38:01 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/06 11:34:10 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

#include <libft.h>
#include <ft_printf.h>

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

int		error(const char *title, const char *msg);
int		skip_spaces(const char **s);
void	token_debug(const t_token *tok);
int		token_fini(t_token *tok);
char	*tokenize(const char *s, t_token *tok);
char	*tokenize_var(const char *s, t_token *tok);
