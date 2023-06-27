/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:54:09 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/09/12 15:48:38 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int			pid;
	int			count;
	const char	*msg;

	if (argc != 3)
	{
		write (1, "usage: <PID> <message>", 23);
		return (-1);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		count = 0;
		msg = argv[2];
		while (msg[count] != '\0')
		{
			send_msg(pid, msg[count]);
			count++;
		}
	}
	return (0);
}
