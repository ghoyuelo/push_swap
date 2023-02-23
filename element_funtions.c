/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_funtions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:41 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:02:41 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_element(t_stack *curr)
{
	int	smallest;

	smallest = curr->content;
	while (curr->next != NULL)
	{
		if (smallest > curr->next->content)
			smallest = curr->next->content;
		curr = curr->next;
	}
	return (smallest);
}

void	del_element(t_stack **stack, int value)
{
	t_stack	*to_remove;
	t_stack	*curr;

	if (*stack == NULL)
		return ;
	curr = *stack;
	if ((*stack)->content == value)
	{
		to_remove = *stack;
		*stack = (*stack)->next;
		free(to_remove);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->content == value)
		{
			to_remove = curr->next;
			curr->next = curr->next->next;
			free(to_remove);
			return ;
		}
		curr = curr->next;
	}
}

int	fst_element(t_stack **stack)
{
	t_stack	*root;

	root = *stack;
	return (root->content);
}

int	fst_ele_index(t_stack **stack)
{
	t_stack	*root;

	root = *stack;
	return (root->index);
}

int	last_element(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr->content);
}
