/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:14:49 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 08:56:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "internal/ft_pipex.h"

static void	ft_clean_data(char **env);

void	ft_clean_pipex(t_pipex *data)
{
	ft_clean_data(data->env);
	ft_clean_data(data->left_cmd);
	ft_clean_data(data->right_cmd);
	if (!data->cmd)
		free(data->cmd);
}

void	ft_clean_fd(int *fd)
{
	close(fd[INFILE]);
	close(fd[OUTFILE]);
}

static void	ft_clean_data(char **data)
{
	char	**data_temp;

	data_temp = data;
	while (*data)
		free(*data++);
	free(data_temp);
}
