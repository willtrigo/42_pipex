/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:08:08 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/17 07:02:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_sprintf.h"
#include "ft_string.h"

void	ft_handle_msg(char *process, char *msg, int fd, int exit_status)
{
	char	*str;
	int		str_len;

	str = NULL;
	if (!ft_strncmp(process, "pipex", ft_str_len("pipex")))
		str_len = ft_sprintf(&str, "pipex: %s\n", msg);
	else
		str_len = ft_sprintf(&str, "pipex: %s: %s\n", process, msg);
	write(fd, str, str_len);
	exit (exit_status);
}
