/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:25:32 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/11 16:26:15 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			count;
	long		temp;
	t_stack_ps	*stack_a;
	t_stack_ps	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	count = 1;
	if (argc == 1)
		return (0);
	if (check_arg(argv) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (argv[count] != NULL)
	{	
		temp = ft_atol (argv[count]);
		if (temp < INT_MIN || temp > INT_MAX)
		{
			ft_printf("Error\n");
			return (1);
		}
		count++;
	}
	if (initialize_stack(argv, &stack_a) || test_duplicated(stack_a) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}				
	if (argc <= 4)
		sort_3(&stack_a);
	else if (argc <= 6)
		sort_5(&stack_a, &stack_b);
	else
	{
		set_index(stack_a);
		radix(&stack_a, &stack_b, (argc - 1));
	}
	free_list (stack_a);
	return (0);
}

int	initialize_stack(char **argv, t_stack_ps **stack)
{
	int			count;
	t_stack_ps	*check_node;

	count = 1;
	while (argv[count] != NULL)
	{
		check_node = ft_new_node(atol (argv[count]));
		if (check_node == NULL)
		{
			free_list (*stack);
			return (1);
		}
		ft_lstadd_back_ps(stack, check_node);
		count++;
	}
	return (0);
}

// int	checking(void)
// {
// 	int	i;
// }

void	free_list(t_stack_ps *stack)
{
	t_stack_ps	*temp;

	while (stack)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
}

// void	print_list(t_stack_ps *stack)
// {
// 	while (stack)
// 	{
// 		printf("%i ", stack->content);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }
