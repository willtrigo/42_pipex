/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:09:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/04/13 12:35:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_default.h"
#include "internal/ast/ft_ast.h"
#include "internal/ft_pipex.h"

t_ast	*ft_ast_constructor(t_pipex *data)
{
	t_ast	*ast_root;

	ast_root = ft_calloc(CHAR_BYTE, sizeof(t_ast));
	if (!ast_root)
	{
		(void)data;
		exit(EXIT_FAILURE);
	}
	return (ast_root);
}

// static void	ft_set_ast_params(int argc, char **argv, t_pipex *data, \
// 				int param_size)
// {
// 	t_ast	*set_ast_params;
//
// 	set_ast_params = ft_calloc(CHAR_BYTE, sizeof(t_ast));
// 	if (!set_ast_params)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_build_ast(argc, argv, set_ast_params, param_size);
// 	data->ast_params = set_ast_params;
//
// }
//
// static void	ft_build_ast(int argc, char **argv, t_ast *ast, int params_size)
// {
// 	if (argc == params_size)
// 	{
//
// 	}
// }
//
// static void	ft_set_ast_params(int argc, char **argv, t_pipex *data, \
// 				int param_size)
// {
// 	t_ast	*set_ast_params;
//
// 	set_ast_params = ft_calloc(CHAR_BYTE, sizeof(t_ast));
// 	if (!set_ast_params)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_build_ast(argc, argv, set_ast_params, param_size);
// 	data->ast_params = set_ast_params;
//
// }
//
// static void	ft_build_ast(int argc, char **argv, t_ast *ast, int params_size)
// {
// 	if (argc == params_size)
// 	{
//
// 	}
// }
