/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:54:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/22 07:37:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "ft_pipex.h"

enum	e_pipex_environ
{
	LEFT_ARG = 1,
	RIGHT_ARG,
};

void	ft_set_pipex_environ(int argc, char **argv, t_pipex *data);
void	ft_set_cmd(t_pipex *data, char **cmd);

#endif
