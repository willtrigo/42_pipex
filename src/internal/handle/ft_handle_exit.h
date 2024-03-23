/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:08:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/23 04:26:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_EXIT_H
# define FT_HANDLE_EXIT_H

#include "internal/ft_pipex.h"

void	ft_handle_msg(char *process, char *msg, int fd);
void	ft_handle_exit(t_pipex *data, int *fd, int exit_status);

#endif
