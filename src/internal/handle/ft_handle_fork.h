/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fork.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:35:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/24 05:53:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_FORK_H
# define FT_HANDLE_FORK_H

# include <sys/types.h>
# include "internal/ft_pipex.h"

void	ft_handle_fork(t_pipex *data, int *fd, pid_t *pid);
void	ft_handle_child(int *fd, int child, t_pipex *data);
void	ft_handle_open(int *fd, int child, t_pipex *data);
void	ft_handle_command(t_pipex *data, char **cmd, int *fd);

#endif
