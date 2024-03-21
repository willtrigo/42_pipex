/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:14:49 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/21 00:51:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/ft_pipex.h"

static void	ft_clean_data(char **env);

void	ft_clean_pipex(t_pipex *data)
{
	ft_clean_data(data->env);
	ft_clean_data(data->left_cmd);
	ft_clean_data(data->right_cmd);
}

static void	ft_clean_data(char **env)
{
	char **env_temp;

	env_temp = env;
	while (*env)
		free(*env++);
	free(env_temp);
}
