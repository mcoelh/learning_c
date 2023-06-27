/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:54:05 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:23:15 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long n);
static void	ft_hex_lower(unsigned long n, int fd);

int	ft_pointer(va_list arg, int fd)
{
	unsigned long	i;
	int				len;

	len = 0;
	i = va_arg(arg, unsigned long);
	write(fd, "0x", 2);
	len = 2;
	ft_hex_lower(i, fd);
	len = len + ft_count(i);
	return (len);
}

static int	ft_count(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_hex_lower(unsigned long n, int fd)
{
	unsigned int	r;

	if (n >= 16)
	{
		ft_hex_lower(n / 16, fd);
	}
	r = n % 16;
	if (r <= 9)
		ft_print_char(r + '0', fd);
	if (r > 9 && r <= 15)
		ft_print_char(r + 'W', fd);
}
