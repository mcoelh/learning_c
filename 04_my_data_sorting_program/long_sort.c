/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:25:16 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/21 19:20:55 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **a_list)
{
	t_node	*aux;

	aux = *a_list;
	while (aux->next != NULL)
	{
		if (aux->nbr > aux->next->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	get_bits(int size)
{
	int	i;

	i = 0;
	while (size > 1)
	{
		size = size / 2;
		i++;
	}
	i++;
	return (i);
}

int	get_size(t_node **lst)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_node **a_list, t_node **b_list, int max_bits)
{
	int	j;
	int	size;
	int	count;

	j = 0;
	size = 0;
	count = 0;
	while (j < max_bits)
	{
		count = 0;
		size = get_size(a_list);
		while (count < size && size != 0)
		{
			to_b(a_list, b_list, j);
			count++;
		}
		while (get_size(b_list) != 0)
			push_pa(b_list, a_list);
		j++;
		if (is_sorted(a_list) && *b_list == NULL)
			break ;
	}
}

void	to_b(t_node **a_list, t_node **b_list, int bit)
{
	t_node	*temp;

	temp = *a_list;
	if (((temp->index >> bit) & 1) == 1)
		rotate_ra(a_list);
	else
		push_pb(a_list, b_list);
}
