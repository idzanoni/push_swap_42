/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:32:58 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/04 19:52:04 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rotate_reverse(t_stack_ps **stack)
{
	t_stack_ps	*temp;

	temp = penultimate_node(*stack);
	temp->next->next = (*stack);
	(*stack) = temp->next;
	temp->next = NULL;
}

void	make_rra(t_stack_ps **stack)
{
	move_rotate_reverse(stack);
	ft_printf("rra\n");
}

void	make_rrb(t_stack_ps **stack)
{
	move_rotate_reverse(stack);
	ft_printf("rrb\n");
}

void	make_rrr(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_rotate_reverse(stack_a);
	move_rotate_reverse(stack_b);
	ft_printf("rrr\n");
}

t_stack_ps	*penultimate_node(t_stack_ps *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
