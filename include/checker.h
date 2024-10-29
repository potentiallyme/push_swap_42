/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:05:04 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/13 17:05:05 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "./push_swap.h"

void	ft_do_rrr(t_list **stack, t_list **hold);
void	ft_do_rr(t_list **stack, t_list **hold);
void	ft_do_ss(t_list *stack, t_list *hold);
void	final_checks(t_list **stack, t_list **hold, int size, int flag);

#endif