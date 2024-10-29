/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:35:33 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/13 16:04:55 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	final_checks(t_list **stack, t_list **hold, int size, int flag)
{
	if (ft_lstsize(*hold))
	{
		ft_printf("KO\n");
		ft_free_stack(hold);
		if (stack)
			ft_free_stack(stack);
		return ;
	}
	if (flag == 0)
		ft_printf("Error\n");
	if (flag == 1)
	{
		if (is_sorted((*stack)) && ft_lstsize((*stack)) == size)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	if (stack)
		ft_free_stack(stack);
	if (hold)
		ft_free_stack(hold);
}

void	ft_do_rrr(t_list **stack, t_list **hold)
{
	ft_rrotate(stack);
	ft_rrotate(hold);
}

void	ft_do_rr(t_list **stack, t_list **hold)
{
	ft_rotate(stack);
	ft_rotate(hold);
}

void	ft_do_ss(t_list *stack, t_list *hold)
{
	ft_swap(stack);
	ft_swap(hold);
}
