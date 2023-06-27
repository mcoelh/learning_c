/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:58:31 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:21:31 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(unsigned int n, int fd);
static int	ft_size_u(unsigned int n);

int	ft_unsigned(va_list arg, int fd)
{
	unsigned int	i;
	unsigned int	len;

	i = va_arg(arg, int);
	ft_nbr(i, fd);
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

static void	ft_nbr(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_nbr(n / 10, fd);
	}
	ft_print_char(n % 10 + '0', fd);
}
