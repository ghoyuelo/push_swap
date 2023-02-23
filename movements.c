/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:01:08 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:01:08 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	swap_first(stack);
	write(1, "sa\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	fst_value;
	int	fst_index;

	if (*stack_b == NULL)
		return ;
	fst_value = fst_element(stack_b);
	fst_index = fst_ele_index(stack_b);
	del_element(stack_b, fst_value);
	insert_beginning(stack_a, fst_value, fst_index);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	int	fst_value;
	int	fst_index;

	if (*stack_a == NULL)
		return ;
	fst_value = fst_element(stack_a);
	fst_index = fst_ele_index(stack_a);
	del_element(stack_a, fst_value);
	insert_beginning(stack_b, fst_value, fst_index);
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}
