/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:24:56 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/13 17:06:12 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_iterate_double(char **s, int (*f)(char **, int, int), int flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag == 1)
		i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!((f)(s, i, j)))
				return (0);
			j++;
		}
		i++;
	}
	return (2);
}
