/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:33:35 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:21:52 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list arg, char c, int fd)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_is_char(arg, fd);
	if (c == 's')
		len = ft_is_str(arg, fd);
	if (c == 'x')
		len = ft_is_hex_l(arg, fd);
	if (c == 'X')
		len = ft_is_hex_u(arg, fd);
	if (c == 'i')
		len = ft_is_int(arg, fd);
	if (c == 'd')
		len = ft_is_int(arg, fd);
	if (c == '%')
	{
		write(fd, "%", 1);
		len = 1;
	}
	if (c == 'p')
		len = ft_pointer(arg, fd);
	if (c == 'u')
		len = ft_unsigned(arg, fd);
	return (len);
}
