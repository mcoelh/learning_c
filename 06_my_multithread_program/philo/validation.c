/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:26:45 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/02/18 19:26:46 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validation(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][0] == '+')
				i++;
			else if (av[j][0] == '-' || !ft_isdigit(av[j][i]))
			{
				error(2);
				return (0);
			}
			else if (ft_isdigit(av[j][i]))
				i++;
		}
		j++;
	}
	return (1);
}

void	error(int n)
{
	if (n == 1)
	{
		printf("Error: Wrong number of arguments, try: ");
		printf("./philo <nbr_philosophers> <time_to_die>"\
			" <time_to_eat> <time_to_sleep>\n");
	}
	if (n == 2)
		printf("Error: At least one of the arguments is wrong\n");
}
