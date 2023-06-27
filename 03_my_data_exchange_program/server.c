/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:12:13 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/09/12 15:50:46 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_msg(int sig)
{
	static int				bits;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c = c | (128 >> bits);
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1 == 1)
	{
		signal(SIGUSR1, receive_msg);
		signal(SIGUSR2, receive_msg);
		pause();
	}
}
