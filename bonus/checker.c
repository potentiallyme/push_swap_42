/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:12:54 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/13 16:08:30 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static t_list	*ft_mklist_checker(char **s, char **av, int yer)
{
	int		i;
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
	return (stack);
}

static int	ft_check_output(t_list **stack, t_list **hold, char *s)
{
	if (!ft_strcmp(s, "pa\n"))
		ft_push(hold, stack);
	else if (!ft_strcmp(s, "pb\n"))
		ft_push(stack, hold);
	else if (!ft_strcmp(s, "ra\n"))
		ft_rotate(stack);
	else if (!ft_strcmp(s, "rb\n"))
		ft_rotate(hold);
	else if (!ft_strcmp(s, "rr\n"))
		ft_do_rr(stack, hold);
	else if (!ft_strcmp(s, "rra\n"))
		ft_rrotate(stack);
	else if (!ft_strcmp(s, "rrb\n"))
		ft_rrotate(hold);
	else if (!ft_strcmp(s, "rrr\n"))
		ft_do_rrr(stack, hold);
	else if (!ft_strcmp(s, "sa\n"))
		ft_swap(*stack);
	else if (!ft_strcmp(s, "sb\n"))
		ft_swap(*hold);
	else if (!ft_strcmp(s, "ss\n"))
		ft_do_ss(*stack, *hold);
	else
		return (0);
	return (1);
}

static int	ft_do_the_job(t_list **stack, t_list **hold)
{
	char	*get;

	get = get_next_line(0);
	while (get)
	{
		if (!ft_check_output(stack, hold, get))
		{
			free(get);
			return (0);
		}
		free(get);
		get = get_next_line(0);
	}
	free(get);
	return (1);
}

int	main(int ac, char **av)
{
	char	**s;
	int		yer;
	int		size;
	t_list	*stack;
	t_list	*hold;

	s = ft_checker(ac, av);
	yer = ft_get_wgb(ac, av);
	hold = NULL;
	if ((!s && yer != 2) || (!s && !ft_iterate_double(av, ft_cval, 1)))
		return (0);
	stack = ft_mklist_checker(s, av, yer);
	size = ft_lstsize(stack);
	if (s)
		ft_free(s);
	if (!ft_do_the_job(&stack, &hold))
		final_checks(&stack, &hold, size, 0);
	else
		final_checks(&stack, &hold, size, 1);
	return (0);
}
