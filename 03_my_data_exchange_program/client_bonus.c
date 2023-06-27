/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:13:17 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/09/12 15:49:37 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_msg(int pid, int c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (128 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(280);
		bit++;
	}
}

void	received_msg(int sig)
{
	if (sig == SIGUSR1)
		write(1, "message received!", 18);
}

int	main(int argc, char **argv)
{
	int					count;
	struct sigaction	receive;

	receive.sa_handler = (void *)received_msg;
	receive.sa_flags = 0;
	sigaction(SIGUSR1, &receive, NULL);
	if (argc != 3)
	{
		write (1, "usage: <PID> <message>", 23);
		return (-1);
	}
	if (argc == 3)
	{
		count = 0;
		while (argv[2][count])
		{
			send_msg(ft_atoi(argv[1]), argv[2][count]);
			count++;
		}
		send_msg(ft_atoi(argv[1]), argv[2][count]);
	}
	return (0);
}
