/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:08:56 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 22:54:24 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_philo)
	{
		if (pthread_mutex_destroy(&data->mutex[i]))
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&data->doctor))
		return (0);
	if (pthread_mutex_destroy(&data->dinner))
		return (0);
	if (pthread_mutex_destroy(&data->print))
		return (0);
	if (pthread_mutex_destroy(&data->stf))
		return (0);
	return (1);
}
