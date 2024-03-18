/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:25:03 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/18 08:00:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_parse.h"
#include "ft_non_standard/ft_non_standard.h"
#include "ft_string.h"
#include "ft_utils.h"

void	ft_parse_arguments(int argc)
{
	if (argc < EXPECT_ARGC)
		ft_handle_msg("pipex", "Too few arguments", STDOUT_FILENO, \
			EXIT_FAILURE);
	else if (argc > EXPECT_ARGC)
		ft_handle_msg("pipex", "Too many arguments", STDOUT_FILENO, \
			EXIT_FAILURE);
}

char	**ft_parse_getenv(char **env)
{
	if (!env)
		return (NULL);
	while (*env && ft_strncmp(*env, "PATH", ft_strlen("PATH")))
		env++;
	if (!*env)
		return (NULL);
	return (ft_split(*env, ':'));
}
