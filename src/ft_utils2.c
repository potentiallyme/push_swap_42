/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:46 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/27 18:26:47 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_define_node_group(t_list *stack)
{
	int	total_size;
	int	group;
	int	divider;

	group = 1;
	total_size = ft_lstsize(stack);
	if (total_size > 200)
		divider = 6;
	else
		divider = 3;
	while (stack)
	{
		while (!stack->group)
		{
			if (stack->index < (total_size * group) / divider
				|| group == divider)
				stack->group = group;
			group++;
		}
		stack = stack->next;
		group = 1;
	}
}

void	ft_rank(t_list *stack, int size)
{
	t_list	*ptr;
	t_list	*highest;
	int		content;

	while (--size > 0)
	{
		ptr = stack;
		content = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > content && ptr->index == 0)
			{
				content = ptr->content;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	ret_max(t_list *stack, long val)
{
	long	max;

	max = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (max > stack->content)
			max = stack->content;
	}
	if (val > max)
		return (1);
	return (0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

long	ft_find_high(t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
