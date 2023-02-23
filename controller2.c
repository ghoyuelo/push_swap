/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:56:00 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/12/14 18:56:53 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_error(t_stack *stack_a)
{
	if (stack_a == NULL)
	{
		deallocate_lst(&stack_a);
		free(stack_a);
		return (1);
	}
	if (repeated(stack_a))
	{
		write(1, "Error\n", 6);
		deallocate_lst(&stack_a);
		free(stack_a);
		return (1);
	}
	return (0);
}

int	repeated(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*save_stack;
	int		rep;

	tmp = stack;
	save_stack = stack;
	rep = 0;
	while (tmp != NULL)
	{
		while (stack != NULL)
		{
			if (tmp->content == stack->content)
				rep++;
			if (rep == 2)
				return (1);
			stack = stack->next;
		}
		rep = 0;
		stack = save_stack;
		tmp = tmp->next;
	}
	return (0);
}
