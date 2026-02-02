/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:06:52 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/22 22:06:54 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	check_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;
	long	prev;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && str[i] == 32)
		i++ ;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++ ;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		prev = result;
		result = (result * 10) + (str[i] - '0');
		if (result < prev)
			return (check_overflow(sign));
		i++ ;
	}
	return (result * sign);
}
