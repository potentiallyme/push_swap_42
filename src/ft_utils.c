/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:39:50 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/25 18:27:45 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ret_min(t_list *stack)
{
	int	pos;
	int	i;
	int	index;

	pos = 0;
	i = 0;
	index = INT_MAX;
	while (stack)
	{
		if (stack->index < index)
		{
			index = stack->index;
			i = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (i);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ret_ab(int val)
{
	if (val < 0)
		val = val * -1;
	return (val);
}

long	ret_val(t_list *stack, int index)
{
	long	val;

	val = 0;
	while (index)
	{
		val = stack->content;
		stack = stack->next;
		index--;
	}
	return (val);
}
