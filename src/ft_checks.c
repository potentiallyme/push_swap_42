/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 03:33:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/30 11:37:30 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_cval(char **s, int i, int j)
{
	long	val;
	char	*tmp;
	int		x;

	x = j;
	val = ft_atoi(s[i]);
	tmp = ft_itoa(val);
	if ((ft_strncmp(tmp, s[i], ft_strlen(s[i])) != 0) || (val > INT_MAX
			|| val < INT_MIN))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	x = i + 1;
	while (s[(x)])
	{
		if (val == ft_atoi(s[(x)]))
			return (0);
		x++;
	}
	return (1);
}

static int	ft_one_arg(char *av, int i)
{
	if (!((av[i] > 47 && av[i] < 58) || (av[i] == 32) || (av[i] == '-')))
		return (0);
	if (av[i] == '-')
	{
		if (av[(i - 1)] != ' ' || !(av[(i + 1)] > 47 && av[(i + 1)] < 58))
			return (0);
	}
	return (1);
}

static int	ft_more_arg(char **av, int ac, int i)
{
	if (!((av[ac][i] > 47 && av[ac][i] < 58) || (av[ac][i] == 32)
			|| (av[ac][i] == '-')))
		return (0);
	if (av[ac][i] == '-')
	{
		if (i != 0 || !(av[ac][(i + 1)] > 47 && av[ac][(i + 1)] < 58))
			return (0);
	}
	return (2);
}

int	ft_get_wgb(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		return (ft_iterate(av[1], ft_one_arg));
	else if (ac > 2)
		return (ft_iterate_double(av, ft_more_arg, 1));
	return (-1);
}

char	**ft_checker(int ac, char **av)
{
	int		wgb;
	char	**s;

	wgb = ft_get_wgb(ac, av);
	s = NULL;
	if (wgb <= 0)
	{
		if (wgb == 0)
			write(2, "Error\n", 6);
		return (NULL);
	}
	else if (wgb == 1)
		s = ft_split(av[1], ' ');
	if (wgb == 1)
		wgb = ft_iterate_double(s, ft_cval, 0);
	else if (wgb == 2)
		wgb = ft_iterate_double(av, ft_cval, 1);
	if (!wgb)
	{
		write(2, "Error\n", 6);
		if (s)
			ft_free(s);
		return (NULL);
	}
	return (s);
}
