/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:09:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 13:31:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "internal/ft_pipex.h"
#include "internal/ft_set.h"
#include "internal/handle/ft_handle_fork.h"
#include "internal/ft_clean.h"

int	ft_pipex(int argc, char **argv)
{
	t_pipex	data;
	int		fd[FD_SIZE];
	pid_t	pid[PID_SIZE];

	ft_set_pipex_environ(argc, argv, &data);
	ft_handle_fork(&data, fd, pid);
	ft_clean_pipex(&data);
	return (((fd[OUTFILE]) & RANGE_STATUS) >> BYTE);
}
