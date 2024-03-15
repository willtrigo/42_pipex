/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:09:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/15 03:43:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"

int	main(void)
{
	ft_putstr_fd("pipex", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
