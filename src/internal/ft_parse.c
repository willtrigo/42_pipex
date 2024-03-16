/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:25:03 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/16 03:26:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_parse.h"
#include "ft_utils.h"

void	ft_parse_arguments(int argc)
{
	if (argc < EXPECT_ARGC)
		ft_handle_msg("pipex", "Too few arguments", STDOUT_FILENO, \
			STDOUT_FILENO);
	else if (argc > EXPECT_ARGC)
		ft_handle_msg("pipex", "Too many arguments", STDOUT_FILENO, \
			STDOUT_FILENO);
}
