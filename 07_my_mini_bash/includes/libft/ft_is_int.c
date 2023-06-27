/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:36:01 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:14:40 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(int n, int fd);
static int	ft_size(int n);

int	ft_is_int(va_list arg, int fd)
{
	long int	i;
	int			len;

	i = va_arg(arg, long int);
	ft_nbr(i, fd);
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

static void	ft_nbr(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_nbr(n / 10, fd);
		}
		ft_print_char(n % 10 + '0', fd);
	}
}
