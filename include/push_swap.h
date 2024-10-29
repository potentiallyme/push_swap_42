/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:05:15 by lmoran            #+#    #+#             */
/*   Updated: 2024/02/13 17:05:18 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/////////////////
// PUSH_SWAP.C //
/////////////////

int		parse_it(char **s, int i, int j);
t_list	*ft_mklist(char **s, char **av, int yer);
t_list	*ft_push_swap(int ac, char **av);

//////////////
// CHECKS.C //
//////////////

char	**ft_checker(int ac, char **av);
int		ft_cval(char **s, int i, int j);
int		ft_get_wgb(int ac, char **av);

/////////////
// UTILS.C //
/////////////

int		is_sorted(t_list *stack);
void	ft_free_stack(t_list **stack);
int		ret_ab(int val);
long	ret_val(t_list *stack, int index);
int		ret_min(t_list *stack);

//////////////
// UTILS2.C //
//////////////

void	ft_rank(t_list *stack, int size);
void	ft_free(char **s);
int		ret_max(t_list *stack, long val);
long	ft_find_high(t_list *stack);
void	ft_define_node_group(t_list *stack);

////////////
// SASB.C //
////////////

void	ft_swap(t_list *stack);
void	do_sa(t_list **stack);
void	do_sb(t_list **hold);
void	do_ss(t_list **stack, t_list **hold);

////////////
// RARB.C //
////////////

void	ft_rotate(t_list **stack);
void	do_ra(t_list **stack);
void	do_rb(t_list **hold);
void	do_rr(t_list **stack, t_list **hold);

//////////////
// RRARRB.c //
//////////////

void	ft_rrotate(t_list **stack);
void	do_rra(t_list **stack);
void	do_rrb(t_list **hold);
void	do_rrr(t_list **stack, t_list **hold);

////////////
// PAPB.C //
////////////

void	ft_push(t_list **src, t_list **dest);
void	do_pa(t_list **stack, t_list **hold);
void	do_pb(t_list **stack, t_list **hold);

/////////////
// SORT.C //
/////////////

void	ft_sort(t_list **stack, t_list **hold);
void	ft_sort_three(t_list **stack);

////////////
// MOVE.C //
////////////

void	ft_move(t_list **stack, t_list **hold, int pos, int t_pos);

////////////
// COST.C //
////////////

void	ft_action(t_list **stack, t_list **hold);

////////////////
// FINISH HIM //
////////////////

void	ft_do_it_all(t_list **stack, t_list *hold);

#endif