/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:58:31 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/29 16:00:11 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(unsigned int n);
static int	ft_size_u(unsigned int n);

int	ft_unsigned(va_list arg)
{
	unsigned int	i;
	unsigned int	len;

	i = va_arg(arg, int);
	ft_nbr(i);
	len = ft_size_u(i);
	return (len);
}

static int	ft_size_u(unsigned int n)
{
	unsigned int	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	ft_nbr(unsigned int n)
{
	if (n > 9)
	{
		ft_nbr(n / 10);
	}
	ft_print_char(n % 10 + '0');
}
