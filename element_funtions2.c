/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_funtions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:58:58 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/12/14 19:16:54 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_ele_index(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr->index);
}

void	insert_beginning(t_stack **stack, int value, int index)
{
	t_stack	*new_lst;

	new_lst = malloc(sizeof(t_stack));
	if (new_lst == NULL)
		return ;
	new_lst->content = value;
	new_lst->index = index;
	new_lst->next = *stack;
	*stack = new_lst;
}

int	find_position(t_stack *stack_a, int index)
{
	t_stack	*curr;
	int		pos;

	curr = stack_a;
	pos = 0;
	while (curr != NULL)
	{
		if (curr->index == index)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (pos++);
}
