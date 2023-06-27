/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:25:28 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:16:56 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'd' || c == 'i' || c == 'x'
		|| c == 'u' || c == 'p' || c == '%' || c == 'X')
		return (1);
	return (0);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_arg(str[i]))
				len = len + ft_convert(arg, str[i], fd);
		}
		else if (str[i] != '%')
		{
			write (fd, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
