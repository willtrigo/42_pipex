/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:37:45 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/22 22:47:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

enum	e_default_pipex
{
	FD_SIZE = 2,
	PID_SIZE = 2,
	INFILE = 0,
	OUTFILE = 1,
	PIPE = 1,
	LEFT_REDIRECT,
	RIGHT_REDIRECT,
	EXEC,
	CMD_NOT_FOUND = 127,
	SIGINT_INTERRUPT = 130,
	RW_R_R = 0644,
	RANGE_STATUS = 0xff00,
	BYTE = 8,
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
	char	*cmd;
	char	*infile;
	char	*outfile;
	int		infile_open;
	int		outfile_open;
};

void	ft_pipex(int agrc, char **argv);

#endif
