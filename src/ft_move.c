/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:14:32 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/23 14:25:49 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rrr(t_list **stack, t_list **hold, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack, hold);
	}
}

static void	ft_rr(t_list **stack, t_list **hold, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack, hold);
	}
}

static void	ft_ra_rra(t_list **stack, int *cost)
{
	while ((*cost))
	{
		if ((*cost) > 0)
		{
			do_ra(stack);
			(*cost)--;
		}
		if ((*cost) < 0)
		{
			do_rra(stack);
			(*cost)++;
		}
	}
}

static void	ft_rb_rrb(t_list **hold, int *cost)
{
	while ((*cost))
	{
		if ((*cost) > 0)
		{
			do_rb(hold);
			(*cost)--;
		}
		if ((*cost) < 0)
		{
			do_rrb(hold);
			(*cost)++;
		}
	}
}

void	ft_move(t_list **stack, t_list **hold, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rrr(stack, hold, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rr(stack, hold, &cost_a, &cost_b);
	ft_ra_rra(stack, &cost_a);
	ft_rb_rrb(hold, &cost_b);
	do_pa(stack, hold);
}
