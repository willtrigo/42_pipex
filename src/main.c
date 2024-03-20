/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:03:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/20 03:02:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/ft_parse.h"
#include "internal/ft_pipex.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(argc);
	ft_pipex(--argc, ++argv);
	exit(EXIT_SUCCESS);
}
