/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:25:03 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/27 01:55:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_non_standard/ft_sprintf.h"
#include "ft_string.h"
#include "ft_default.h"
#include "internal/ft_parse.h"
#include "internal/handle/ft_handle_exit.h"

void	ft_parse_arguments(int argc)
{
	if (argc < EXPECT_ARGC)
	{
		ft_handle_msg("pipex", "Too few arguments", STDERR_FILENO);
		ft_handle_exit(NULL, NULL, EXIT_FAILURE);
	}
	else if (argc > EXPECT_ARGC)
	{
		ft_handle_msg("pipex", "Too many arguments", STDERR_FILENO);
		ft_handle_exit(NULL, NULL, EXIT_FAILURE);
	}
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

char	*ft_parse_path(char *exec_process, char **env)
{
	char	*path;

	if (access(exec_process, X_OK | F_OK | R_OK) == DEFAULT)
		return (exec_process);
	if (*exec_process == '.' || *exec_process == '/')
		return (exec_process);
	while (*env)
	{
		ft_sprintf(&path, "%s/%s", *env++, exec_process);
		if (!access(path, X_OK | F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}
