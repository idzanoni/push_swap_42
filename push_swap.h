/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:04:28 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/10 17:05:47 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "./libs/libft/libft.h"
# include "./libs/ft_printf/ft_printf.h"

typedef struct s_stack_ps
{
	int					content;
	struct s_stack_ps	*next;
	int					index;
}					t_stack_ps;

int			check_arg(char **arg);
long		ft_atol(const char *c_ptr);
void		ft_lstadd_back_ps(t_stack_ps **lst, t_stack_ps *new);
t_stack_ps	*ft_new_node(int content);
void		print_list(t_stack_ps *stack);
void		free_list(t_stack_ps *stack);
void		move_swap(t_stack_ps **stack);
void		make_sa(t_stack_ps **stack);
void		make_sb(t_stack_ps **stack);
void		make_ss(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		move_rotate_reverse(t_stack_ps **stack);
void		make_rra(t_stack_ps **stack);
void		make_rrb(t_stack_ps **stack);
void		make_rrr(t_stack_ps **stack_a, t_stack_ps **stack_b);
t_stack_ps	*penultimate_node(t_stack_ps *stack);
void		move_rotate(t_stack_ps **stack);
void		make_ra(t_stack_ps **stack);
void		make_rb(t_stack_ps **stack);
void		make_rr(t_stack_ps **stack_a, t_stack_ps **stack_b);
t_stack_ps	*last_node(t_stack_ps *stack);
void		move_push_to_a(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		move_push_to_b(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		make_pa(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		make_pb(t_stack_ps **stack_a, t_stack_ps **stack_b);
int			is_sorted(t_stack_ps *stack);
int			test_duplicated(t_stack_ps *stack_a);
void		sort_3(t_stack_ps **stack);
int			find_highest(t_stack_ps *stack);
int			find_smallest(t_stack_ps *stack);
void		sort_5(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		move_to_top(int smallest, t_stack_ps **stack);

#endif
