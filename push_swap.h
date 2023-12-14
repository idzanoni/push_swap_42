/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:04:28 by izanoni           #+#    #+#             */
/*   Updated: 2023/12/12 16:50:01 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "./libs/libft/libft.h"
# include "./libs/ft_printf/ft_printf.h"

typedef struct s_stack_ps
{
	int					content;
	struct s_stack_ps	*next;
}					t_stack_ps;

#endif