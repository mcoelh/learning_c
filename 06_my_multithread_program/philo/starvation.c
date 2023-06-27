/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starvation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:55:29 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 23:20:41 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *people)
{
	unsigned long	time;

	time = get_time() - people->data->time_start;
	if (time - people->last_meal >= people->data->die)
	{
		pthread_mutex_lock(&people->data->doctor);
		people->data->dead = 1;
		pthread_mutex_unlock(&people->data->doctor);
		pthread_mutex_lock(&people->data->print);
		time = get_time() - people->data->time_start;
		printf("%ld %d died\n", time, people->id + 1);
		pthread_mutex_unlock(&people->data->print);
		return (1);
	}
	return (0);
}

int	end_dinner(t_philo *people)
{
	pthread_mutex_lock(&people->data->doctor);
	if (people->data->dead == 1)
	{
		pthread_mutex_unlock(&people->data->doctor);
		return (1);
	}
	pthread_mutex_unlock(&people->data->doctor);
	return (0);
}
