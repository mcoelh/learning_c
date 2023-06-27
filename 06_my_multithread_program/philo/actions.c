/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:05:46 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/28 15:13:51 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	food_routine(t_philo *people)
{
	if (people->in_hand == 2)
	{
		print_status(people, "is eating");
		is_eating(people);
		drop_fork(people, people->own_fork);
		drop_fork(people, people->friend_fork);
		return (1);
	}
	return (0);
}

int	is_eating(t_philo *people)
{
	pthread_mutex_lock(&people->data->stf);
	people->last_meal = get_time() - people->data->time_start;
	people->times_eat = people->times_eat + 1;
	if (people->times_eat == people->data->x_eat)
		people->data->satisfied++;
	pthread_mutex_unlock(&people->data->stf);
	time_holder(people, people->data->eat);
	return (0);
}

int	is_sleeping(t_philo *people)
{
	print_status(people, "is sleeping");
	time_holder(people, people->data->sleep);
	return (0);
}

int	is_thinking(t_philo *people)
{
	print_status(people, "is thinking");
	return (0);
}
