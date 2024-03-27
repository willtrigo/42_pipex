/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:35:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/27 01:51:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_default.h"
#include "internal/handle/ft_handle_fork.h"
#include "internal/ft_pipex.h"
#include "internal/handle/ft_handle_command.h"
#include "internal/handle/ft_handle_exit.h"
#include "internal/ft_clean.h"

static void	ft_handle_open_pipe(t_pipex *data, int *fd);
static void	ft_handle_child(int *fd, int child, t_pipex *data);
static void	ft_handle_open(int *fd, int child, t_pipex *data);

void	ft_handle_fork(t_pipex *data, int *fd, pid_t *pid)
{
	ft_handle_open_pipe(data, fd);
	pid[INFILE] = fork();
	if (pid[INFILE] <= FAIL)
	{
		ft_handle_msg("fork", strerror(errno), STDERR_FILENO);
		ft_handle_exit(data, fd, EXIT_FAILURE);
	}
	if (pid[INFILE] == DEFAULT)
		ft_handle_child(fd, INFILE, data);
	pid[OUTFILE] = fork();
	if (pid[OUTFILE] <= FAIL)
	{
		ft_handle_msg("fork", strerror(errno), STDERR_FILENO);
		ft_handle_exit(data, fd, EXIT_FAILURE);
	}
	if (pid[OUTFILE] == DEFAULT)
		ft_handle_child(fd, OUTFILE, data);
	ft_clean_fd(fd);
	waitpid(pid[OUTFILE], &fd[OUTFILE], WUNTRACED);
}

static void	ft_handle_open_pipe(t_pipex *data, int *fd)
{
	if (pipe(fd) == FAIL)
	{
		ft_handle_msg("pipe", strerror(errno), STDERR_FILENO);
		ft_handle_exit(data, fd, SIGINT_INTERRUPT);
	}
}

static void	ft_handle_child(int *fd, int child, t_pipex *data)
{
	if (child == INFILE)
	{
		ft_handle_open(fd, child, data);
		dup2(data->infile_open, STDIN_FILENO);
		dup2(fd[OUTFILE], STDOUT_FILENO);
		ft_clean_fd(fd);
		ft_handle_command(data, data->left_cmd, fd, INFILE);
	}
	else
	{
		ft_handle_open(fd, child, data);
		dup2(data->outfile_open, STDOUT_FILENO);
		dup2(fd[INFILE], STDIN_FILENO);
		ft_clean_fd(fd);
		ft_handle_command(data, data->right_cmd, fd, OUTFILE);
	}
}

static void	ft_handle_open(int *fd, int child, t_pipex *data)
{
	if (child == INFILE)
	{
		data->infile_open = open(data->infile, O_RDONLY, RW_R_R);
		if (data->infile_open <= FAIL)
		{
			ft_clean_fd(fd);
			ft_handle_msg(data->infile, strerror(errno), STDERR_FILENO);
			ft_handle_exit(data, fd, EXIT_FAILURE);
		}
	}
	else
	{
		data->outfile_open = open(data->outfile, O_TRUNC | O_RDWR | O_CREAT, \
			RW_R_R);
		if (data->outfile_open <= FAIL)
		{
			ft_clean_fd(fd);
			ft_handle_msg(data->outfile, strerror(errno), STDERR_FILENO);
			ft_handle_exit(data, fd, EXIT_FAILURE);
		}
	}
}
