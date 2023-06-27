/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:38:56 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 19:04:24 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *people, char *str)
{
	unsigned long	time;

	pthread_mutex_lock(&people->data->doctor);
	if (people->data->dead == 0)
	{
		pthread_mutex_lock(&people->data->print);
		time = get_time() - people->data->time_start;
		printf("%ld %d %s\n", time, people->id + 1 \
		, str);
		pthread_mutex_unlock(&people->data->print);
		pthread_mutex_unlock(&people->data->doctor);
		return (1);
	}
	pthread_mutex_unlock(&people->data->doctor);
	return (0);
}
