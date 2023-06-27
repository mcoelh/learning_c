/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:10:06 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 22:46:45 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker(t_data *data)
{
	int	i;

	i = 0;
	while (7)
	{
		pthread_mutex_lock(&data->stf);
		if (check_death(&data->people[i]))
		{
			pthread_mutex_unlock(&data->stf);
			break ;
		}
		if (satisfied(&data->people[i], data->satisfied))
		{
			pthread_mutex_unlock(&data->stf);
			break ;
		}
		pthread_mutex_unlock(&data->stf);
		i++;
		if (i == data->max_philo)
			i = 0;
	}
}

int	satisfied(t_philo *people, int satisfied)
{
	if (people->data->max_philo == satisfied)
	{
		pthread_mutex_lock(&people->data->doctor);
		people->data->dead = 1;
		pthread_mutex_unlock(&people->data->doctor);
		return (1);
	}
	return (0);
}
