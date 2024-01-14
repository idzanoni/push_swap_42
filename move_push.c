/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:35:05 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/12 17:04:37 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push_to_a(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	t_stack_ps	*temp;

	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = temp;
}

void	move_push_to_b(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	t_stack_ps	*temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = temp;
}

void	make_pa(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_push_to_a(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	make_pb(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_push_to_b(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	move_to_top(int smallest, t_stack_ps **stack)
{
	t_stack_ps	*temp;

	temp = *stack;
	while (temp->content != smallest)
		temp = temp->next;
	if (temp->next == NULL)
	{
		make_rra(stack);
		return ;
	}	
	while ((*stack)->content != smallest)
		make_ra(stack);
}
