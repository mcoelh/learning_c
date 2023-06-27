/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:22:31 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 20:34:38 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *nptr)
{
	int	signal;
	int	count;
	int	value;

	signal = 1;
	count = 0;
	value = 0;
	if (nptr == NULL)
		return (0);
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
