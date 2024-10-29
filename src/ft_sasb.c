/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sasb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:01:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/23 14:29:08 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_list *stack)
{
	long	content;
	int		index;

	content = 0;
	index = 0;
	if (!stack || !stack->next)
		return ;
	content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content;
	index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = index;
}

void	do_sa(t_list **stack)
{
	ft_swap(*stack);
	write(1, "sa\n", 3);
}

void	do_sb(t_list **hold)
{
	ft_swap(*hold);
	write(1, "sb\n", 3);
}

void	do_ss(t_list **stack, t_list **hold)
{
	ft_swap(*stack);
	ft_swap(*hold);
	write(1, "ss\n", 3);
}
