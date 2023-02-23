/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:55:17 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/14 13:35:07 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_int_limits(int sign, long int res)
{
	if (res * sign > 2147483647 || res * sign < -2147483648)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
}

int	ft_atoi(const char *str)
{
	long long int	ct[3];

	if (!str || str[0] == 0)
		return (0);
	if (ft_isspace(*str))
		return (ft_atoi(str + 1));
	if (str[0] == '+' || str[0] == '-')
		ct[0] = 0;
	else
		ct[0] = -1;
	if (str[0] == '-')
		ct[2] = -1;
	else
		ct[2] = 1;
	ct[1] = 0;
	while (str[++ct[0]])
	{
		if (str[ct[0]] < '0' || str[ct[0]] > '9')
			return (ct[1] * ct[2]);
		ct[1] = 10 * ct[1] + str[ct[0]] - '0';
	}
	ft_check_int_limits(ct[2], ct[1]);
	return (ct[1] * ct[2]);
}
