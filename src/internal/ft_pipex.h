/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:37:45 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/20 06:18:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

enum	e_default_pipex
{
	FD_SIZE = 2,
	PID_SIZE = 2,
	PIPE = 1,
	LEFT_REDIRECT,
	RIGHT_REDIRECT,
	EXEC
};

typedef struct s_ast	t_ast;
struct s_ast
{
	t_ast	*left;
	t_ast	*right;
	char	*type;
	char	**exec;
};

typedef struct s_pipex	t_pipex;
struct s_pipex
{
	char	**env;
	char	**left_cmd;
	char	**right_cmd;
	char	*infile;
	char	*outfile;
};

void	ft_pipex(int agrc, char **argv);

#endif
