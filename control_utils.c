/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:27:59 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/12 00:27:59 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	minus_checker(char *str)
{
	int	j;

	j = 1;
	while (str[j] != '\0')
	{
		if (str[j] == '-')
			return (0);
		j++;
	}
	return (1);
}

void	insert_end(t_stack **root, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	tmp = *root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	ft_atoi_max_min(const char *str)
{
	long	result;
	int		minus;

	result = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		if ((result * minus <= -2147483648) || (result * minus >= 2147483648))
			return (0);
		str++;
	}
	return (1);
}
