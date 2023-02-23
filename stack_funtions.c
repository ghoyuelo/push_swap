/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funtions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:48 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:02:48 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_string(char **argv)
{
	int		i;
	char	**str;
	t_stack	*stack;

	stack = NULL;
	str = ft_split(argv[1], ' ');
	i = 0;
	while (str[i])
	{
		if (minus_checker(str[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		insert_end(&stack, ft_atoi(str[i]));
		i++;
	}
	free_pointer (str);
	return (stack);
}

t_stack	*fill_args(char **argv)
{
	int		i;
	int		j;
	t_stack	*stack;
	char	**s;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		s = ft_split(argv[i], ' ');
		j = -1;
		while (s[++j])
			insert_end(&stack, ft_atoi(s[j]));
		free_pointer(s);
		i++;
	}
	return (stack);
}

void	add_index(t_stack **stack, int value, int index)
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next != NULL)
	{
		if (curr->content == value)
		{
			curr->index = index;
			return ;
		}
		curr = curr->next;
	}
	if (curr->content == value)
		curr->index = index;
}

int	is_ordened(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
