/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:03:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/16 03:07:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "internal/ft_parse.h"

int	main(int argc, char **argv, char **envp)
{
	(void)envp;
	(void)argv;
	ft_parse_arguments(argc);
	exit(EXIT_SUCCESS);
}
