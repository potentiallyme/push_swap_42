/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:35:54 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/30 11:38:07 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_finish(t_list **stack)
{
	int	pos;
	int	size;

	pos = ret_min(*stack);
	size = ft_lstsize(*stack);
	if (pos > (size / 2))
	{
		while (pos < size)
		{
			do_rra(stack);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			do_ra(stack);
			pos--;
		}
	}
}

void	ft_do_it_all(t_list **stack, t_list *hold)
{
	if (is_sorted(*stack))
		return ;
	if (ft_lstsize(*stack) > 200)
		ft_sort(stack, &hold);
	else
		ft_sort(stack, &hold);
	ft_sort_three(stack);
	while (hold)
		ft_action(stack, &hold);
	if (!is_sorted(*stack))
		ft_finish(stack);
}
