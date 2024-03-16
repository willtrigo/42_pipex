/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:08:08 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/16 03:21:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"

void	ft_handle_msg(char *process, char *msg, int fd, int exit_status)
{
	ft_putstr_fd(process, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(msg, fd);
	exit (exit_status);
}
