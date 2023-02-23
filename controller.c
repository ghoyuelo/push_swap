/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:57:42 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/12/14 22:00:15 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (checker(argc, argv) == 1)
		return (1);
	return (0);
}

int	checker(int argc, char **argv)
{
	if (argc > 1)
	{
		if (check_chars(argc - 1, argv) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if (check_string(argv) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}	
	}
	return (0);
}

int	check_chars(int n, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i <= n)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) ||
					argv[i][j] == '-' || argv[i][j] == ' ')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_string(char **argv)
{
	int	i;

	i = 0;
	if (argv[2] == NULL)
	{
		if (ft_strcmp(argv[1], "         ") == 1)
			return (1);
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] < '0' && argv[1][i] > '9' && argv[1][i] != '-')
				return (1);
			i++;
		}
	}
	else
	{
		if (check_args(argv) == 1)
			return (1);
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_atoi_max_min(argv[i]) == 0)
			return (1);
		while (argv[i][j])
		{
			if (argv[1][i] < '0' && argv[1][i] > '9' && argv[1][i] != '-')
				return (1);
			j++;
		}
		if (minus_checker(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
