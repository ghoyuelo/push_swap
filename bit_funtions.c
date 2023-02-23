/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_funtions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:41 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/10/14 00:02:41 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_bits(int n)
{
	unsigned int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

// The first bit of the number is 0
int	is_bit_set(int index, int bit)
{
	if (index & (1 << bit))
		return (1);
	return (0);
}
