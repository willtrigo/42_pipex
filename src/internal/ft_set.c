/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:55:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/09/17 23:42:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_non_standard/ft_sprintf.h"
#include "ft_stdlib.h"
#include "ft_default.h"
#include "ft_set.h"
#include "ft_pipex.h"
#include "ft_parse.h"

// static void	ft_set_ast_params(int argc, char **argv, t_pipex *data, \
// 				int param_size);
// static void	ft_build_ast(int argc, char **argv, t_ast *ast, int params_size);

void	ft_set_pipex_environ(int argc, char **argv, t_pipex *data)
{
	data->env = ft_parse_getenv(__environ);
	// ft_set_ast_params(argc, argv, data, argc);
	data->left_cmd = ft_split(argv[LEFT_ARG], ' ');
	data->right_cmd = ft_split(argv[RIGHT_ARG], ' ');
	data->infile = *argv;
	data->outfile = *(argv + --argc);
}

void	ft_set_cmd_path(t_pipex *data, char **cmd)
{
	char	*bin;

	bin = ft_parse_path(*cmd, data->env);
	ft_sprintf(&data->cmd, "%s", bin);
	if (!bin)
		free(bin);
}

