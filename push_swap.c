/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:57:44 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/12/14 22:16:37 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		ra(stack_a);
	else if (size == 3)
		short_three(stack_a);
	else if (size == 4)
		short_four(stack_a, stack_b);
	else if (size <= 67)
		short_ten(stack_a, stack_b);
	else
		radix_short(stack_a, stack_b);
}

void	index_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		size;
	int		i;
	int		small;

	small = 0;
	i = 0;
	size = lst_size(*stack);
	tmp = copy_lst(*stack);
	while (i < size)
	{
		small = smallest_element(tmp);
		add_index(stack, small, i);
		del_element(&tmp, small);
		i++;
	}
	deallocate_lst(&tmp);
}

t_stack	*init_stack(char **argv)
{
	t_stack	*stack;

	if (argv[2] == NULL)
		stack = fill_string(argv);
	else
		stack = fill_args(argv);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (errors(argc, argv) == 1)
		return (0);
	stack_a = init_stack(argv);
	if (stack_a_error(stack_a) == 1)
		return (0);
	index_stack(&stack_a);
	if (!is_ordened(stack_a))
		resolve_stack(&stack_a, &stack_b);
	deallocate_lst(&stack_a);
	deallocate_lst(&stack_b);
	return (0);
}
