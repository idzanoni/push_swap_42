/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:04:28 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/12 17:10:24 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack_ps
{
	int					content;
	struct s_stack_ps	*next;
	int					index;
}					t_stack_ps;

//push_swap.c
int			checking(char **argv, t_stack_ps **stack_a);
int			initialize_stack(char **argv, t_stack_ps **stack);
void		free_list(t_stack_ps *stack);

//checking.c
int			check_arg(char **arg);
int			test_duplicated(t_stack_ps *stack_a);
void		set_index(t_stack_ps *stack);

//create.c
t_stack_ps	*ft_new_node(int content);
void		ft_lstadd_back_ps(t_stack_ps **lst, t_stack_ps *new);
t_stack_ps	*ft_lstlast(t_stack_ps *lst);
long		ft_atol(const char *c_ptr);

//move_push.c
void		move_push_to_a(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		move_push_to_b(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		make_pa(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		make_pb(t_stack_ps **stack_a, t_stack_ps **stack_b);
void		move_to_top(int smallest, t_stack_ps **stack);

//move_rotate_r.c
void		move_rotate_reverse(t_stack_ps **stack);
void		make_rra(t_stack_ps **stack);
void		make_rrb(t_stack_ps **stack);
void		make_rrr(t_stack_ps **stack_a, t_stack_ps **stack_b);
t_stack_ps	*penultimate_node(t_stack_ps *stack);

//move_rotate.c
void		move_rotate(t_stack_ps **stack);
void		make_ra(t_stack_ps **stack);
void		make_rb(t_stack_ps **stack);
void		make_rr(t_stack_ps **stack_a, t_stack_ps **stack_b);
t_stack_ps	*last_node(t_stack_ps *stack);

//move_swap.c
void		move_swap(t_stack_ps **stack);
void		make_sa(t_stack_ps **stack);
void		make_sb(t_stack_ps **stack);
void		make_ss(t_stack_ps **stack_a, t_stack_ps **stack_b);

//sort.c
int			is_sorted(t_stack_ps *stack);
void		sort_3(t_stack_ps **stack);
int			find_highest(t_stack_ps *stack);
int			find_smallest(t_stack_ps *stack);
void		sort_5(t_stack_ps **stack_a, t_stack_ps **stack_b);

//radix.c
int			count_digits(int highest_index);
void		radix(t_stack_ps **stack_a, t_stack_ps **stack_b, int size_stack);

#endif
