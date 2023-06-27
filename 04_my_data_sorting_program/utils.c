/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:30:36 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 18:42:03 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long int	ft_atol(char *nptr)
{
	int			signal;
	int			count;
	long int	value;

	signal = 1;
	count = 0;
	value = 0;
	while ((nptr[count] == 32) || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			signal = signal * -1;
		count++;
	}
	while (ft_isdigit(nptr[count]))
	{
		value = (value * 10) + nptr[count] - '0';
		count++;
	}
	if (nptr[count] != '\0')
		return ((long int) INT_MAX + 1);
	return (signal * value);
}

size_t	ft_strlen(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
