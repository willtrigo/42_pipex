/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:37:45 by dande-je          #+#    #+#             */
/*   Updated: 2024/04/03 20:08:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "internal/ast/ft_ast.h"

enum	e_default_pipex
{
	FD_SIZE = 2,
	PID_SIZE = 2,
	INFILE = 0,
	OUTFILE = 1,
	/* PIPE = 1, */
	LEFT_REDIRECT,
	RIGHT_REDIRECT,
	EXEC,
	RW_R_R = 0644,
};

enum	e_exit_pipex
{
	CMD_NOT_FOUND = 127,
	SIGINT_INTERRUPT = 130,
	RANGE_STATUS = 0xff00,
	BYTE = 8,
};

typedef struct s_pipex	t_pipex;
struct s_pipex
{
	char	**env;
	t_ast	*ast_params;
	t_ast	*node;
	char	**left_cmd;
	char	**right_cmd;
	char	*cmd;
	char	*infile;
	char	*outfile;
	int		infile_open;
	int		outfile_open;
};

int	ft_pipex(int agrc, char **argv);

#endif
