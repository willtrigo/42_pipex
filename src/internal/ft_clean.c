/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:14:49 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/19 19:11:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_clean_getenv(char **env)
{
	char **env_temp;

	env_temp = env;
	while (*env)
		free(*env++);
	free(env_temp);
}
