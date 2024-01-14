/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:33:05 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/12 17:03:40 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rotate(t_stack_ps **stack)
{
	t_stack_ps	*temp;

	temp = last_node(*stack);
	temp->next = (*stack);
	(*stack) = (*stack)->next;
	temp->next->next = NULL;
}

void	make_ra(t_stack_ps **stack)
{
	move_rotate(stack);
	write(1, "ra\n", 3);
}

void	make_rb(t_stack_ps **stack)
{
	move_rotate(stack);
	write(1, "rb\n", 3);
}

void	make_rr(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_rotate(stack_a);
	move_rotate(stack_b);
	write(1, "rr\n", 3);
}

t_stack_ps	*last_node(t_stack_ps *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
