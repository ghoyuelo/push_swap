/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:25 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:02:25 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first(t_stack **stack)
{
	int		fst_node;
	int		fst_index;
	int		scnd_node;
	int		scnd_index;
	t_stack	*curr;

	curr = *stack;
	fst_node = curr->content;
	fst_index = curr->index;
	scnd_node = curr->next->content;
	curr->content = scnd_node;
	scnd_index = curr->next->index;
	curr->index = scnd_index;
	curr = curr->next;
	curr->content = fst_node;
	curr->index = fst_index;
}

void	rotate(t_stack **stack)
{
	t_stack	*curr;
	int		lst_value;
	int		lst_index;

	lst_value = fst_element(stack);
	lst_index = fst_ele_index(stack);
	if (*stack == NULL)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
	{
		curr->content = curr->next->content;
		curr->index = curr->next->index;
		curr = curr->next;
	}
	curr->content = curr->next->content;
	curr->index = curr->next->index;
	curr->next->content = lst_value;
	curr->next->index = lst_index;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*curr;
	int		temp1;
	int		temp2;
	int		temp1_in;
	int		temp2_in;

	if (*stack == NULL)
		return ;
	curr = *stack;
	temp1 = fst_element(stack);
	temp1_in = fst_ele_index(stack);
	curr->content = last_element(stack);
	curr->index = last_ele_index(stack);
	curr = curr->next;
	while (curr != NULL)
	{
		temp2 = curr->content;
		temp2_in = curr->index;
		curr->content = temp1;
		curr->index = temp1_in;
		temp1 = temp2;
		temp1_in = temp2_in;
		curr = curr->next;
	}
}

void	move_top(t_stack **stack_a, int index)
{
	t_stack	*curr;
	int		pos;
	int		size;
	int		middle;

	size = lst_size(*stack_a);
	pos = find_position(*stack_a, index);
	middle = size / 2;
	curr = *stack_a;
	while (pos != 0)
	{
		if (size % 2 == 0 && (pos >= middle))
			rra(stack_a);
		else if (pos >= (middle + 1))
			rra(stack_a);
		else
			ra(stack_a);
		pos = find_position(*stack_a, index);
	}
}

int	count_move_top(t_stack **stack_a, int index)
{
	int	pos;
	int	size;
	int	middle;
	int	moves;

	size = lst_size(*stack_a);
	pos = find_position(*stack_a, index);
	middle = size / 2;
	if (size % 2 == 0)
	{	
		if (pos >= middle)
			moves = (size - pos) + 1;
		else
			moves = pos;
	}
	else
	{
		middle++;
		if (pos < middle)
			moves = pos;
		else
			moves = (size - pos);
	}
	return (moves);
}
