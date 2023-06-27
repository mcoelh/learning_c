/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:58:49 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 14:59:08 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	count;
	int	value;

	signal = 1;
	count = 0;
	value = 0;
	while ((nptr[count] == 32) || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (ft_isdigit(nptr[count]))
	{
		value = (value * 10) + nptr[count] - '0';
		count++;
	}
	return (signal * value);
}
