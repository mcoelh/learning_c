/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:24:34 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 20:43:17 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		error(1);
		return (0);
	}
	else if (!validation(ac, av))
		return (0);
	else if (!start_data(ac, av, &data))
		return (0);
	start_dinner(&data);
	free(data.mutex);
	free(data.forks);
	return (0);
}

int	start_data(int ac, char **av, t_data *data)
{
	data->max_philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 5)
		data->x_eat = -1;
	else
		data->x_eat = ft_atoi(av[5]);
	data->time_start = get_time();
	data->dead = 0;
	data->satisfied = 0;
	if (data->max_philo <= 0 || data->die <= 0 || data->eat <= 0 \
		|| data->sleep <= 0 || data->x_eat == 0)
	{	
		error (2);
		return (0);
	}
	start_mallocs(data);
	return (1);
}

int	start_mallocs(t_data *data)
{
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->max_philo);
	if (!data->mutex)
		return (0);
	data->forks = malloc(sizeof(int) * data->max_philo);
	if (!data->forks)
		return (1);
	return (4);
}

void	start_dinner(t_data *data)
{
	create_mutexes(data);
	create_threads(data);
}
