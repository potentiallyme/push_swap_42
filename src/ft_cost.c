/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:13:38 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/25 22:32:29 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_ret_pos(t_list *stack, int index)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index == index)
		{
			i = pos;
			return (i);
		}
		pos++;
		stack = stack->next;
	}
	return (i);
}

static int	ft_find_target(t_list *stack, int index)
{
	t_list	*tmp;
	int		target;

	tmp = stack;
	target = INT_MAX;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < target)
			target = tmp->index;
		tmp = tmp->next;
	}
	if (target != INT_MAX)
		return (ft_ret_pos(stack, target));
	return (ret_min(stack));
}

static void	ft_cost(t_list **stack, t_list **hold)
{
	t_list	*tmp_b;
	int		pos;
	int		t_pos;

	tmp_b = *hold;
	while (tmp_b)
	{
		pos = ft_ret_pos(*hold, tmp_b->index);
		t_pos = ft_find_target(*stack, tmp_b->index);
		tmp_b->cost_b = pos;
		if (pos > ft_lstsize(*hold) / 2)
			tmp_b->cost_b = (ft_lstsize(*hold) - pos) * -1;
		tmp_b->cost_a = t_pos;
		if (t_pos > ft_lstsize(*stack) / 2)
			tmp_b->cost_a = (ft_lstsize(*stack) - t_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	ft_action(t_list **stack, t_list **hold)
{
	t_list	*tmp;
	int		best;
	int		cost_a;
	int		cost_b;

	tmp = *hold;
	best = INT_MAX;
	ft_cost(stack, hold);
	while (tmp)
	{
		if (ret_ab(tmp->cost_a) + ret_ab(tmp->cost_b) < ret_ab(best))
		{
			best = ret_ab(tmp->cost_a) + ret_ab(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move(stack, hold, cost_a, cost_b);
}
