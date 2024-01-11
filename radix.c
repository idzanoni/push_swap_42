/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:40:27 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/11 16:22:59 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digits(int highest_index)
{
	int	digit;

	digit = 1;
	while (highest_index > 1)
	{
		highest_index = highest_index / 2;
		digit++;
	}
	return (digit);
}

void	radix(t_stack_ps **stack_a, t_stack_ps **stack_b, int size_stack)
{
	int	digits;
	int	bit_shift;
	int	count;

	digits = count_digits (size_stack - 1);
	bit_shift = 0;
	while (bit_shift < digits)
	{
		count = size_stack;
		while (count != 0)
		{
			if (!(((*stack_a)->index >> bit_shift) & 1))
				make_pb(stack_a, stack_b);
			else
				make_ra(stack_a);
			count--;
		}
		while (*stack_b)
			make_pa (stack_a, stack_b);
		bit_shift++;
	}
}
// size_stack = argc - 1