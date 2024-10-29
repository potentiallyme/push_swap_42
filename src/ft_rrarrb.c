/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrarrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:51:38 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/23 14:28:35 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*sclast;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	while (*stack && (*stack)->next)
	{
		sclast = *stack;
		*stack = (*stack)->next;
	}
	*stack = last;
	(*stack)->next = tmp;
	sclast->next = NULL;
}

void	do_rra(t_list **stack)
{
	ft_rrotate(stack);
	write(1, "rra\n", 4);
}

void	do_rrb(t_list **hold)
{
	ft_rrotate(hold);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_list **stack, t_list **hold)
{
	ft_rrotate(stack);
	ft_rrotate(hold);
	write(1, "rrr\n", 4);
}
