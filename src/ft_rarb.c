/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:54:21 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/23 14:28:56 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_list **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	do_rb(t_list **hold)
{
	ft_rotate(hold);
	write(1, "rb\n", 3);
}

void	do_rr(t_list **stack, t_list **hold)
{
	ft_rotate(stack);
	ft_rotate(hold);
	write(1, "rr\n", 3);
}
