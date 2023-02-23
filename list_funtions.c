/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:28:02 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/12 00:28:02 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate_lst(t_stack **root)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = *root;
	while (tmp != NULL)
	{
		aux = tmp;
		tmp = tmp->next;
		free(aux);
	}
	*root = NULL;
}

int	lst_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

t_stack	*copy_lst(t_stack *stack)
{
	t_stack	*curr;

	if (stack == NULL)
		return (NULL);
	curr = NULL;
	while (stack->next != NULL)
	{
		insert_end(&curr, stack->content);
		stack = stack->next;
	}
	insert_end(&curr, stack->content);
	return (curr);
}
