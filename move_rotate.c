/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:33:05 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/04 19:49:04 by izanoni          ###   ########.fr       */
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
	ft_printf("ra\n");
}

void	make_rb(t_stack_ps **stack)
{
	move_rotate(stack);
	ft_printf("rb\n");
}

void	make_rr(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_rotate(stack_a);
	move_rotate(stack_b);
	ft_printf("rr\n");
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
