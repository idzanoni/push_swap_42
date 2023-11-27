/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:25:32 by izanoni           #+#    #+#             */
/*   Updated: 2023/11/25 19:28:30 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_arg(char **arg);
long	ft_atol(const char *c_ptr);
t_stack_ps	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_stack_ps **lst, t_stack_ps *new);

int	main(int argc, char **argv)
{
	int		count;
	long	temp;
	t_stack_ps	*stack_a;

	count = 0;
	if (check_arg(argv) == 1)
	{
		ft_printf("error\n");
		return (1);
	}
	temp = atol (argv[count]);
	if (temp < INT_MIN || temp > INT_MAX)
	{
		ft_printf("error\n");
		return (1);
	}
	// ft_lstnew_ps((int)argv[count]);
	// ft_lstadd_back_ps
	return (0);
}

t_stack_ps	*ft_lstnew_ps(int content)
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

	count = 0;
	line = 0;
	while (arg[line])
	{
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
	ft_printf("error\n");
}
