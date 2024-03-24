/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:35:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 05:52:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_non_standard/ft_sprintf.h"
#include "ft_default.h"
#include "internal/handle/ft_handle_fork.h"
#include "internal/handle/ft_handle_exit.h"
#include "internal/ft_set.h"
#include "internal/ft_parse.h"
#include "internal/ft_clean.h"

void	ft_handle_fork(t_pipex *data, int *fd, pid_t *pid)
{
	pid[INFILE] = fork();
	if (pid[INFILE] <= FAIL)
	{
		ft_handle_msg("fork", "failed to initiate", STDERR_FILENO);
		ft_handle_exit(data, fd, EXIT_FAILURE);
	}
	if (pid[INFILE] == DEFAULT)
		ft_handle_child(fd, INFILE, data);
	pid[OUTFILE] = fork();
	if (pid[OUTFILE] <= FAIL)
	{
		ft_handle_msg("fork", "failed to initiate", STDERR_FILENO);
		ft_handle_exit(data, fd, EXIT_FAILURE);
	}
	if (pid[OUTFILE] == DEFAULT)
		ft_handle_child(fd, OUTFILE, data);
	ft_clean_fd(fd);
	waitpid(pid[OUTFILE], &fd[OUTFILE], WUNTRACED);
}

void	ft_handle_child(int *fd, int child, t_pipex *data)
{
	if (child == INFILE)
	{
		ft_handle_open(fd, child, data);
		dup2(data->infile_open, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_clean_fd(fd);
		ft_set_cmd(data, &*data->left_cmd);
		ft_handle_command(data, data->left_cmd, fd);
	}
	else
	{
		ft_handle_open(fd, child, data);
		dup2(data->outfile_open, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		ft_clean_fd(fd);
		ft_set_cmd(data, &*data->right_cmd);
		ft_handle_command(data, data->right_cmd, fd);
	}
}

void	ft_handle_open(int *fd, int child, t_pipex *data)
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

void	ft_handle_command(t_pipex *data, char **cmd, int *fd)
{
	char	*bin;
	char	*exec;

	bin = parse_path(*cmd, data->env);
	if (access(bin, F_OK | X_OK) == DEFAULT)
	{
		ft_sprintf(&exec, "%s", bin);
		execve(exec, cmd, data->env);
		ft_handle_msg(data->cmd, strerror(errno), STDERR_FILENO);
		ft_handle_exit(data, fd, errno);
	}
	else
	{
		ft_handle_msg(bin, "command not found", STDERR_FILENO);
		ft_handle_exit(data, fd, CMD_NOT_FOUND);
	}
}
