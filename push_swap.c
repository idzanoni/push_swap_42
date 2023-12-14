/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:25:32 by izanoni           #+#    #+#             */
/*   Updated: 2023/12/14 20:51:36 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_arg(char **arg);
long		ft_atol(const char *c_ptr);
void		ft_lstadd_back_ps(t_stack_ps **lst, t_stack_ps *new);
t_stack_ps	*ft_new_node(int content);
void		print_list(t_stack_ps *stack);
void		free_list(t_stack_ps *stack);

int	main(int argc, char **argv)
{
	int			count;
	long		temp;
	t_stack_ps	*stack_a;
	t_stack_ps	*check_node;

	stack_a = NULL;
	count = 1;
	if (check_arg(argv) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (argv[count] != NULL)
	{	
		temp = atol (argv[count]);
		if (temp < INT_MIN || temp > INT_MAX)
		{
			ft_printf("Error\n");
			return (1);
		}
		count++;
	}
	count = 1;
	while (argv[count] != NULL)
	{
		check_node = ft_new_node(atol (argv[count]));
		if (check_node == NULL)
		{
			free_list (stack_a);
			return (1);
		}
		ft_lstadd_back_ps(&stack_a, check_node);
		count++;
	}
	print_list(stack_a);
	return (0);
}

// int	test_duplicated(char **argv)
// {
// 	int	i;
// 	int	counter;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		counter = 0;
// 		while (argv[counter])
// 		{
// 			if (counter != i)
// 			{
// 				if (ft_str_is_equal(argv[i], argv[counter]))
// 					return (-1);
// 			}
// 			counter++;
// 		}
// 		i++;
// 	}
// 	return (0);
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

void	print_list(t_stack_ps *stack)
{
	while (stack)
	{
		printf("%i, ", stack->content);
		stack = stack->next;
	}
}

t_stack_ps	*ft_new_node(int content)
{
	t_stack_ps	*new;

	new = malloc (1 * sizeof(t_stack_ps));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_back_ps(t_stack_ps **lst, t_stack_ps *new)
{
	t_stack_ps	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

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
		while (arg[line][count])
		{
			if (arg[line][count] >= '0' && arg[line][count] <= '9')
				count++;
			else
			{
				return (1);
			}
		}
		line++;
	}
	return (0);
}

long	ft_atol(const char *c_ptr)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (c_ptr == NULL)
		return (0);
	while (c_ptr[i] == ' ' || (c_ptr[i] >= 9 && c_ptr[i] <= 13))
		i++;
	if (c_ptr[i] == '+' || c_ptr[i] == '-')
	{
		if (c_ptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (c_ptr[i] >= '0' && c_ptr[i] <= '9')
	{
		result = result * 10 + (c_ptr[i] - '0');
		i++;
	}
	return (sign * result);
}

void	return_error(void)
{
	ft_printf("Error\n");
}
