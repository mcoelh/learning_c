/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:06:28 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/29 18:22:03 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_convert(va_list arg, char c);
int		ft_is_char(va_list arg);
int		ft_is_str(va_list arg);
int		ft_is_hex_l(va_list arg);
int		ft_is_hex_u(va_list arg);
int		ft_is_int(va_list arg);
int		ft_pointer(va_list arg);
int		ft_unsigned(va_list arg);
void	ft_print_char(int c);
#endif
