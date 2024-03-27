/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:45 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/27 08:05:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_default.h"
#include "internal/handle/ft_handle_command.h"
#include "internal/ft_set.h"
#include "internal/handle/ft_handle_exit.h"

static void	ft_handle_command_fd(t_pipex *data, int child);
static void	ft_handle_commmand_exit_code(t_pipex *data, char **cmd, int *fd);

void	ft_handle_command(t_pipex *data, char **cmd, int *fd, int child)
{
	int		valid_fd_folder;

	ft_set_cmd(data, cmd);
	valid_fd_folder = open(data->cmd, O_DIRECTORY | O_RDONLY, RW_R_R);
	if (valid_fd_folder != FAIL)
	{
		close(valid_fd_folder);
		ft_handle_command_fd(data, child);
		ft_handle_msg(data->cmd, "Is a directory", STDERR_FILENO);
		free(data->cmd);
		ft_handle_exit(data, fd, EACCES_STATUS);
	}
	execve(data->cmd, cmd, data->env);
	ft_handle_command_fd(data, child);
	ft_handle_commmand_exit_code(data, cmd, fd);
}

static void	ft_handle_command_fd(t_pipex *data, int child)
{
	if (child == INFILE)
		close(data->infile_open);
	else if (child == OUTFILE)
		close(data->outfile_open);
	close(INFILE);
	close(OUTFILE);
}

static void	ft_handle_commmand_exit_code(t_pipex *data, char **cmd, int *fd)
{
	char	*check_bar;

	check_bar = ft_strrchr(*cmd, '/');
	if ((access(*cmd, R_OK | W_OK) == FAIL) && !access(*cmd, F_OK))
	{
		ft_handle_msg(*cmd, "Permission denied", STDERR_FILENO);
		free(data->cmd);
		ft_handle_exit(data, fd, EACCES_STATUS);
	}
	else if (!(**cmd == '/' || **cmd == '.'))
	{
		if (check_bar)
			ft_handle_msg(*cmd, strerror(errno), STDERR_FILENO);
		else
		{
			ft_handle_msg(*cmd, "command not found", STDERR_FILENO);
			free(check_bar);
		}
		free(data->cmd);
		ft_handle_exit(data, fd, ENOENT_STATUS);
	}
	ft_handle_msg(*cmd, strerror(errno), STDERR_FILENO);
	free(data->cmd);
	ft_handle_exit(data, fd, STDERR_FILENO);
}
