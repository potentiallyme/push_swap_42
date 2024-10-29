/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:59:39 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/30 11:37:51 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_mklist(char **s, char **av, int yer)
{
	int		i;
	int		size;
	t_list	*stack;

	stack = NULL;
	if (yer == 1)
	{
		i = -1;
		while (s[++i])
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(s[i])));
	}
	else if (yer == 2)
	{
		i = 0;
		while (av[++i])
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
	}
	size = ft_lstsize(stack);
	ft_rank(stack, size);
	ft_define_node_group(stack);
	return (stack);
}

t_list	*ft_push_swap(int ac, char **av)
{
	char	**s;
	int		yer;
	t_list	*stack;
	t_list	*hold;

	hold = NULL;
	s = ft_checker(ac, av);
	yer = ft_get_wgb(ac, av);
	if ((!s && yer != 2) || (!s && !ft_iterate_double(av, ft_cval, 1)))
		return (NULL);
	stack = ft_mklist(s, av, yer);
	if (s)
		ft_free(s);
	ft_do_it_all(&stack, hold);
	return (stack);
}

int	main(int ac, char **av)
{
	t_list	*stack;

	stack = ft_push_swap(ac, av);
	if (stack)
		ft_free_stack(&stack);
	return (0);
}
