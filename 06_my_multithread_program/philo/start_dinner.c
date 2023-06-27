/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:35:11 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/07 15:34:14 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_philo)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->doctor, NULL);
	pthread_mutex_init(&data->dinner, NULL);
	pthread_mutex_init(&data->stf, NULL);
}

void	create_threads(t_data *data)
{
	pthread_t	*p;
	int			i;

	p = malloc(sizeof(pthread_t) * data->max_philo);
	if (!p)
		return ;
	data->people = malloc(sizeof(t_philo) * data->max_philo);
	if (!data->people)
		return ;
	i = 0;
	while (i < data->max_philo)
	{
		people_data(i, data, &data->people[i]);
		i++;
	}
	i = 0;
	while (i < data->max_philo)
	{
		pthread_create(&p[i], NULL, &routine, &data->people[i]);
		i++;
	}
	checker(data);
	end_threads(data, p);
}

void	people_data(int i, t_data *data, t_philo *people)
{
	people->id = i;
	people->data = data;
	people->data->forks[i] = 0;
	people->max_p = data->max_philo;
	people->in_hand = 0;
	people->last_meal = 0;
	people->times_eat = 0;
	people->own_fork = i;
	people->friend_fork = (people->id + 1) % people->max_p;
}

void	*routine(void *arg)
{
	t_philo	*people;

	people = (t_philo *)arg;
	if ((people->id + 1) % 2 == 0)
		usleep(800);
	while (666)
	{
		if (end_dinner(people))
		{
			check_forks(people);
			break ;
		}
		both_forks(people);
		food_routine(people);
		is_sleeping(people);
		is_thinking(people);
	}
	return (NULL);
}

void	end_threads(t_data *data, pthread_t *p)
{
	int	i;

	i = 0;
	while (i < data->max_philo)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	end_mutexes(data);
	free(p);
	free(data->people);
}
