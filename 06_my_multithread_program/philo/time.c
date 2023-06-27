/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:00 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 16:46:07 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	time_holder(t_philo *people, unsigned long action)
{
	unsigned long	time;

	time = get_time() + action;
	while (time > get_time())
	{
		if (end_dinner(people))
			return (0);
		usleep(300);
	}
	return (1);
}
