/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:06:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/04/03 20:08:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AST_H 
# define FT_AST_H

typedef enum	e_ast_type
{
	COMMAND,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
} t_ast_type;

typedef struct	s_heredoc	t_heredoc;
struct	s_heredoc
{
	char	*delimiter;
	char	*content;
};

typedef struct s_ast	t_ast;
struct s_ast
{
	t_ast_type	type;
	union
	{
		t_ast		*left_node;
		t_ast		*right_node;
		char		*filename;
		char		**exec;
		t_heredoc	heredoc;
		int			open;
	} u_data;
	/* t_ast		*next; */
};

#endif
