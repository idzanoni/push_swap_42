/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:03:17 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/10 16:01:58 by izanoni          ###   ########.fr       */
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
		make_ra(stack);
	else if ((*stack)->next->content == highest)
		make_rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		make_sa(stack);
}

int	find_highest(t_stack_ps *stack)
{
	int		highest;

	highest = stack->content;
	while (stack)
	{
		if (stack->content > highest)
			highest = stack->content;
		stack = stack->next;
	}
	return (highest);
}

int	find_smallest(t_stack_ps *stack)
{
	int		smallest;

	smallest = stack->content;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

void	sort_5(t_stack_ps **stack_a, t_stack_ps **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	move_to_top(find_smallest(*stack_a), stack_a);
	make_pb(stack_a, stack_b);
	move_to_top(find_smallest(*stack_a), stack_a);
	make_pb(stack_a, stack_b);
	sort_3(stack_a);
	make_pa(stack_a, stack_b);
	make_pa(stack_a, stack_b);
}
