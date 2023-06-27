/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:36:01 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/29 15:37:17 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(int n);
static int	ft_size(int n);

int	ft_is_int(va_list arg)
{
	long int	i;
	int			len;

	i = va_arg(arg, long int);
	ft_nbr(i);
	len = ft_size(i);
	return (len);
}

static int	ft_size(int n)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 0;
	if (nbr == 0)
		len = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len = 1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	ft_nbr(int n)
{
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_nbr(n / 10);
		}
		ft_print_char(n % 10 + '0');
	}
}
