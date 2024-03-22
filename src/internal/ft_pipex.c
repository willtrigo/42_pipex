/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:09:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/22 08:21:00 by dande-je         ###   ########.fr       */
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
#include "internal/ft_clean.h"
#include "internal/ft_parse.h"
#include "internal/ft_utils.h"

static void	ft_handle_fork(t_pipex *data);
static void	ft_handle_child(int *fd, int child, t_pipex *data);
static void	ft_handle_open(int *fd, int child, t_pipex *data);
static void	ft_handle_command(t_pipex *data, char **cmd);

void	ft_pipex(int argc, char **argv)
{
	t_pipex	data;

	ft_set_pipex_environ(argc, argv, &data);
	ft_handle_fork(&data);
	ft_clean_pipex(&data);
}

static void	ft_handle_fork(t_pipex *data)
{
	int		fd[FD_SIZE];
	pid_t	pid[PID_SIZE];

	if (pipe(fd) == FAIL)
		ft_handle_msg("pipe", strerror(errno), STDERR_FILENO, SIGINT_INTERRUPT);
	pid[INFILE] = fork();
	if (pid[INFILE] <= FAIL)
		ft_handle_msg("fork", "failed to initiate", STDERR_FILENO, \
			EXIT_FAILURE);
	if (pid[INFILE] == DEFAULT)
		ft_handle_child(fd, INFILE, data);
	pid[OUTFILE] = fork();
	if (pid[OUTFILE] <= FAIL)
		ft_handle_msg("fork", "failed to initiate", STDERR_FILENO, \
			EXIT_FAILURE);
	if (pid[OUTFILE] == DEFAULT)
		ft_handle_child(fd, OUTFILE, data);
	ft_clean_fd(fd);
	waitpid(pid[INFILE], NULL, DEFAULT);
	waitpid(pid[OUTFILE], NULL, DEFAULT);
}

static void	ft_handle_child(int *fd, int child, t_pipex *data)
{
	if (child == INFILE)
	{
		ft_handle_open(fd, child, data);
		dup2(data->infile_open, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_clean_fd(fd);
		ft_set_cmd(data, &*data->left_cmd);
		ft_handle_command(data, data->left_cmd);
	}
	else
	{
		ft_handle_open(fd, child, data);
		dup2(data->outfile_open, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		ft_clean_fd(fd);
		ft_set_cmd(data, &*data->right_cmd);
		ft_handle_command(data, data->right_cmd);
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
			ft_handle_msg(data->infile, strerror(errno), STDERR_FILENO, \
				EXIT_FAILURE);
		}
	}
	else
	{
		data->outfile_open = open(data->outfile, O_TRUNC | O_RDWR | O_CREAT, \
			RW_R_R);
		if (data->outfile_open <= FAIL)
		{
			ft_clean_fd(fd);
			ft_handle_msg(data->outfile, strerror(errno), STDERR_FILENO, \
				EXIT_FAILURE);
		}
	}
}

static void	ft_handle_command(t_pipex *data, char **cmd)
{
	if (!access(parse_path(*cmd, data->env), F_OK))
	{
		if (execve(parse_path(*cmd, data->env), cmd, data->env))
			ft_handle_msg(data->cmd, strerror(errno), STDERR_FILENO, errno);
	}
	else
		ft_handle_msg(data->cmd, "command not found", STDERR_FILENO, CMD_NOT_FOUND);
}
