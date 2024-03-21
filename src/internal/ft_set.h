/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:54:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/21 05:06:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "ft_pipex.h"

enum	e_pipex_environ
{
	LEFT_ARG = 1,
	RIGHT_ARG,
	CMD_ARG = 0,
};

void	set_pipex_environ(int argc, char **argv, t_pipex *data);

#endif
