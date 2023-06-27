/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:06:28 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 16:11:48 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_convert(va_list arg, char c, int fd);
int		ft_is_char(va_list arg, int fd);
int		ft_is_str(va_list arg, int fd);
int		ft_is_hex_l(va_list arg, int fd);
int		ft_is_hex_u(va_list arg, int fd);
int		ft_is_int(va_list arg, int fd);
int		ft_pointer(va_list arg, int fd);
int		ft_unsigned(va_list arg, int fd);
void	ft_print_char(int c, int fd);
#endif
