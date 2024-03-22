/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:55:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/22 08:21:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_non_standard/ft_sprintf.h"
#include "ft_set.h"
#include "ft_pipex.h"
#include "ft_parse.h"

void	ft_set_pipex_environ(int argc, char **argv, t_pipex *data)
{
	data->env = ft_parse_getenv(__environ);
	data->left_cmd = ft_split(argv[LEFT_ARG], ' ');
	data->right_cmd = ft_split(argv[RIGHT_ARG], ' ');
	data->infile = *argv;
	data->outfile = *(argv + --argc);
}

void	ft_set_cmd(t_pipex *data, char **cmd)
{
	char	*bin;

	if (!data->cmd)
		free(data->cmd);
	bin = parse_path(*cmd, data->env);
	if (!bin)
		free(*cmd);
	ft_sprintf(&data->cmd, "%s", bin);
	free(bin);
}
