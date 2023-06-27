/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:33:35 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/29 18:22:09 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_is_char(arg);
	if (c == 's')
		len = ft_is_str(arg);
	if (c == 'x')
		len = ft_is_hex_l(arg);
	if (c == 'X')
		len = ft_is_hex_u(arg);
	if (c == 'i')
		len = ft_is_int(arg);
	if (c == 'd')
		len = ft_is_int(arg);
	if (c == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	if (c == 'p')
		len = ft_pointer(arg);
	if (c == 'u')
		len = ft_unsigned(arg);
	return (len);
}
