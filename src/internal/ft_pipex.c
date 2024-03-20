/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:09:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/20 07:56:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "internal/ft_pipex.h"
#include "ft_non_standard/ft_non_standard.h"
#include "ft_non_standard/ft_sprintf.h"
#include "internal/ft_parse.h"
#include "internal/ft_clean.h"

char	*parse_path(char *exec_process, char **env);
#include <stdio.h>
void	ft_pipex(int argc, char **argv)
{
	t_pipex	data;

	data.env = ft_parse_getenv(__environ);
	data.left_cmd = ft_split(argv[1], ' ');
	data.right_cmd = ft_split(argv[2], ' ');
	printf("%s first cmd\n", parse_path(data.left_cmd[0], data.env));
	printf("%s second cmd\n", parse_path(data.right_cmd[0], data.env));
	data.infile = *argv;
	data.outfile = *(argv + --argc);
	printf("%s infile | %s outfile\n", data.infile, data.outfile);
	ft_clean_getenv(data.env);
}

char	*parse_path(char *exec_process, char **env)
{
	char *path;

	if (!access(exec_process, F_OK))
		return (exec_process);
	while (*env)
	{
		ft_sprintf(&path, "%s/%s", *env++, exec_process);
		if (!access(path, F_OK))
			return (exec_process);
		free(path);
	}
	return (NULL);
}
