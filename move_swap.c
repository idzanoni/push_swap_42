/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:33:00 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/12 17:02:35 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_swap(t_stack_ps **stack)
{
	t_stack_ps	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	make_sa(t_stack_ps **stack)
{
	move_swap(stack);
	write(1, "sa\n", 3);
}

void	make_sb(t_stack_ps **stack)
{
	move_swap(stack);
	write(1, "sb\n", 3);
}

void	make_ss(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	move_swap(stack_a);
	move_swap(stack_b);
	write(1, "ss\n", 3);
}
