/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:37:26 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/30 11:37:58 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_list **stack)
{
	long	ind;

	if (is_sorted(*stack))
		return ;
	ind = ft_find_high(*stack);
	if ((*stack)->index == ind)
		do_ra(stack);
	else if ((*stack)->next->index == ind)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

static void	ft_cut(t_list **stack, t_list **hold, int low)
{
	do_pb(stack, hold);
	if ((*stack)->group == low || (*stack)->group == low + 1)
		do_rb(hold);
	else
		do_rr(stack, hold);
}

static int	ft_getlow(t_list *stack)
{
	int	low;

	low = INT_MAX;
	while (stack)
	{
		if (stack->group < low)
			low = stack->group;
		stack = stack->next;
	}
	return (low);
}

void	ft_sort(t_list **stack, t_list **hold)
{
	int	low;

	low = ft_getlow(*stack);
	while ((*stack) && ft_lstsize(*stack) > 3)
	{
		if ((*stack)->group == low)
			do_pb(stack, hold);
		else if ((*stack)->group == low + 1)
			ft_cut(stack, hold, low);
		else
			do_ra(stack);
		low = ft_getlow(*stack);
	}
}
