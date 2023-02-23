/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:14 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:02:14 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_three(t_stack **stack_a)
{
	int		pos_0;
	int		pos_1;
	t_stack	*curr;

	curr = *stack_a;
	index_stack(&curr);
	pos_0 = curr->index;
	pos_1 = curr->next->index;
	if (pos_0 == 1 && pos_1 == 2)
		rra(&curr);
	else if (pos_0 == 2 && pos_1 == 0)
		ra(&curr);
	else
		sa(&curr);
	if (!is_ordened(curr))
		short_three(&curr);
}

void	short_four(t_stack **stack_a, t_stack **stack_b)
{
	move_top(stack_a, 0);
	pb(stack_b, stack_a);
	short_three(stack_a);
	pa(stack_a, stack_b);
}

void	short_ten(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	while (lst_size(*stack_a) != 3 && !is_ordened(*stack_a))
	{
		move_top(stack_a, size - lst_size(*stack_a));
		pb(stack_b, stack_a);
	}
	if (lst_size(*stack_a) == 3)
		short_three(stack_a);
	while (lst_size(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	radix_short(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bit;
	int		i;
	t_stack	*curr;
	int		size;
	int		j;

	max_bit = count_bits(lst_size(*stack_a) - 1);
	size = lst_size(*stack_a);
	i = -1;
	while (i++ < (max_bit - 1))
	{
		j = 0;
		while (j < size)
		{
			curr = *stack_a;
			if (is_bit_set(curr->index, i) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			j++;
		}
		while (lst_size(*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}
