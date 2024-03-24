/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:08:08 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 05:06:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_sprintf.h"
#include "ft_string.h"
#include "internal/ft_clean.h"
#include "internal/ft_pipex.h"

void	ft_handle_msg(char *process, char *msg, int fd)
{
	char	*str;
	int		str_len;

	str = NULL;
	if (!ft_strncmp(process, "pipex", ft_str_len("pipex")))
		str_len = ft_sprintf(&str, "pipex: %s\n", msg);
	else
		str_len = ft_sprintf(&str, "pipex: %s: %s\n", process, msg);
	write(fd, str, str_len);
	free(str);
}

void	ft_handle_exit(t_pipex *data, int *fd, int exit_status)
{
	ft_clean_fd(fd);
	ft_clean_pipex(data);
	if (exit_status == ENOENT)
		exit_status = 127;
	exit (exit_status);
}