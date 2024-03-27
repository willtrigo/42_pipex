/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:27:36 by dande-je          #+#    #+#             */
/*   Updated: 2024/03/26 04:29:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

enum e_parse
{
	EXPECT_ARGC = 5,
};

void	ft_parse_arguments(int argc);
char	**ft_parse_getenv(char **env);
char	*ft_parse_path(char *exec_process, char **env);

#endif
