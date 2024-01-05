/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:03:17 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/05 20:36:36 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_ps *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_3(t_stack_ps **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest(*stack);
	if ((*stack)->content == highest)
		do_ra(stack);
	else if ((*stack)->next->content == highest)
		do_rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		do_sa(stack);
}

int	find_highest(t_stack_ps *stack)
{
	int		high;

	high = stack->content;
	while (stack)
	{
		if (stack->content > high)
			high = stack->content;
		stack = stack->next;
	}
	return (high);
}

int	find_smallest(t_stack_ps *stack)
{
	int		small;

	small = stack->content;
	while (stack)
	{
		if (stack->content < small)
			small = stack->content;
		stack = stack->next;
	}
	return (small);
}

void	sort_5(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	find_smallest(*stack_a);
	move_push_to_b(stack_a, stack_b);
	find_smallest(*stack_a);
	move_push_to_b(stack_a, stack_b);
	sort_3(*stack_a);
	move_push_to_a(stack_a, stack_b);
	move_push_to_a(stack_a, stack_b);
}
