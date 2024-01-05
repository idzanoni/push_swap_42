/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:22:02 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/04 20:29:56 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack_ps *stack)
{
	while (stack)
	{
		if (stack > stack->next)
			return (1);
		stack = stack->next;
	}
	return (0);
}
