/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:37:35 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 16:09:24 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_char(va_list arg, int fd)
{
	int	c;

	c = va_arg(arg, int);
	ft_print_char(c, fd);
	return (1);
}
