/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:33:57 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/12 15:52:47 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **arg)
{
	int	count;
	int	line;

	line = 1;
	while (arg[line])
	{
		count = 0;
		if (arg[line][0] == '-')
			count++;
		if (arg[line][0] == '\0')
			return (1);
		while (arg[line][count])
		{
			if (arg[line][count] >= '0' && arg[line][count] <= '9')
				count++;
			else
				return (1);
		}
		line++;
	}
	return (0);
}

int	test_duplicated(t_stack_ps *stack_a)
{
	t_stack_ps	*comper;
	t_stack_ps	*compared;

	compared = stack_a;
	while (compared != NULL)
	{
		comper = compared->next;
		while (comper != NULL)
		{
			if (compared->content == comper->content)
			{
				free_list(stack_a);
				return (1);
			}
			comper = comper->next;
		}
		compared = compared->next;
	}
	return (0);
}

void	set_index(t_stack_ps *stack)
{
	t_stack_ps	*comper;
	t_stack_ps	*compared;

	comper = stack;
	while (comper != NULL)
	{
		compared = stack;
		while (compared != NULL)
		{
			if (comper->content > compared->content)
			{
				(comper)->index++;
			}
			compared = compared->next;
		}
		comper = comper->next;
	}
}
