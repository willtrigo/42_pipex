/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:03:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/18 08:18:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "internal/ft_parse.h"
#include "internal/ft_clean.h"

int	main(int argc, char **argv, char **envp)
{
	char	**env;

	(void)argv;
	ft_parse_arguments(argc);
	env = ft_parse_getenv(envp);
	ft_clean_getenv(env);
	free(env);
	exit(EXIT_SUCCESS);
}

