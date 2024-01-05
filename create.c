/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:37:18 by izanoni           #+#    #+#             */
/*   Updated: 2024/01/05 15:37:38 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
