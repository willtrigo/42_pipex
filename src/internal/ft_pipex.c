/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:09:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 05:54:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "ft_default.h"
#include "internal/ft_pipex.h"
#include "internal/ft_set.h"
#include "internal/handle/ft_handle_fork.h"
#include "internal/handle/ft_handle_exit.h"
#include "internal/ft_clean.h"

void	ft_pipex(int argc, char **argv)
{
	t_pipex	data;
	int		fd[FD_SIZE];
	pid_t	pid[PID_SIZE];

	ft_set_pipex_environ(argc, argv, &data);
	if (pipe(fd) == FAIL)
	{
		ft_handle_msg("pipe", strerror(errno), STDERR_FILENO);
		ft_handle_exit(&data, fd, SIGINT_INTERRUPT);
	}
	ft_handle_fork(&data, fd, pid);
	ft_clean_pipex(&data);
	exit(((fd[OUTFILE]) & RANGE_STATUS) >> BYTE);
}
