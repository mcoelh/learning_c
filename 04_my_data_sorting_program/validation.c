/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:24:38 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 19:17:07 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 3)
	{	
		if (!av[1] || !is_nbr(ac, av) || !nbr_range(av))
			write(2, "Error\n", 6);
		return (0);
	}
	else if (is_repeated(av) || !is_nbr(ac, av) || !nbr_range(av))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	else
		return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	minus;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		minus = s1[i] - s2[i];
	return (minus);
}

int	is_repeated(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (i != j && (ft_strcmp(av[i], av[j]) == 0))
				return (1);
			else if (i != j && (ft_atol(av[i]) == ft_atol(av[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		while (av[i][j])
		{
			if ((av[i][0] == '+' || av[i][0] == '-') && (ft_isdigit(av[i][1])))
				j++;
			else if (ft_isdigit(av[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	nbr_range(char **av)
{
	int		i;
	long	nbr;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11)
			return (0);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
