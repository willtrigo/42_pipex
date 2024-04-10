/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:09:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/04/03 20:16:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_default.h"
#include "internal/ast/ft_ast.h"
#include "internal/ft_pipex.h"

t_ast	*ft_astnew(t_pipex *data)
{
	t_ast	*astnew;

	astnew = ft_calloc(CHAR_BYTE, sizeof(t_ast));
	if (!astnew)
	{
		(void)data;
		exit(EXIT_FAILURE);
	}
	return (astnew);
}
