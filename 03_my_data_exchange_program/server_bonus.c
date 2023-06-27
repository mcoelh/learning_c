/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:52:06 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/09/12 15:53:50 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	receive_msg(int sig, siginfo_t *u_pid)
{
	static int				bits;
	static int				p_client;
	static unsigned char	c;

	p_client = u_pid->si_pid;
	if (sig == SIGUSR1)
		c = c | (128 >> bits);
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		if (c == '\0')
		{
			kill(p_client, SIGUSR1);
		}
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	report;

	report.sa_handler = (void *)receive_msg;
	report.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1 == 1)
	{
		sigaction(SIGUSR1, &report, NULL);
		sigaction(SIGUSR2, &report, NULL);
		pause();
	}
}
