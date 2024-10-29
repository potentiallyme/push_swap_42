/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:44:12 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/25 22:05:29 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_list **stack, t_list **hold)
{
	ft_push(hold, stack);
	write(1, "pa\n", 3);
}

void	do_pb(t_list **stack, t_list **hold)
{
	ft_push(stack, hold);
	write(1, "pb\n", 3);
}
