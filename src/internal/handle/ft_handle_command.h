/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:39 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/25 12:48:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_COMMAND_H
# define FT_HANDLE_COMMAND_H

# include "internal/ft_pipex.h"

void	ft_handle_command(t_pipex *data, char **cmd, int *fd, int child);

#endif
