/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:17:26 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/23 18:10:25 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(int ac, char **av)
{
	int	*array;
	int	count;
	int	j;
	int	aux;

	j = 0;
	count = -1;
	array = malloc(sizeof(int) * ac -1);
	while (++j < ac)
		array[++count] = ft_atol(av[j]);
	count = 0;
	while (count < ac - 2)
	{
		if (array[count] > array[count + 1])
		{
			aux = array[count];
			array[count] = array[count + 1];
			array[count + 1] = aux;
			count = 0;
		}
		else
			count++;
	}
	return (array);
}

void	transform_index(t_node *lst_a, int *array, int size)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = lst_a;
	while (i < size)
	{
		lst_a = temp;
		while (lst_a != NULL)
		{
			if (lst_a->nbr == array[i])
			{
				lst_a->index = i;
				break ;
			}
			lst_a = lst_a->next;
		}
		i++;
	}
}
