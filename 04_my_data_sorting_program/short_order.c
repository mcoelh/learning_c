/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:52:44 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 12:59:43 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)->nbr;
	second = (*lst)->next->nbr;
	third = ft_last(*lst)->nbr;
	if ((first > second) && (second > third) && (first > third))
	{
		rotate_ra(lst);
		sa_swap(lst);
	}
	if ((first > second) && (second < third) && (first > third))
		rotate_ra(lst);
	if ((first < second) && (second > third) && (first > third))
		reverse_rra(lst);
	if ((first > second) && (first < third) && (second < third))
		sa_swap(lst);
	if ((first < second) && (second > third) && (first < third))
	{
		reverse_rra(lst);
		sa_swap(lst);
	}
}

void	sort_four(t_node **a_list, t_node **b_list, int *aux)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	while (*a_list != NULL)
	{
		if ((*a_list)->nbr == aux[0])
		{
			push_pb(a_list, b_list);
			key++;
			if (key == 1)
				break ;
		}
		rotate_ra(a_list);
	}
	sort_three(a_list);
	push_pa(b_list, a_list);
}

void	find_shorter(t_node **a_list, t_node **b_list, int *aux)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	while (*a_list != NULL)
	{
		if ((*a_list)->nbr == aux[0] || (*a_list)->nbr == aux[1])
		{
			push_pb(a_list, b_list);
			key++;
			if ((*a_list)->nbr == aux[0] || (*a_list)->nbr == aux[1])
			{	
				push_pb(a_list, b_list);
				key++;
			}
			if (key == 2)
				break ;
		}
		rotate_ra(a_list);
	}
}

void	sort_five(t_node **a_list, t_node **b_list, int *aux)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	find_shorter(a_list, b_list, aux);
	key = 2;
	sort_three(a_list);
	while (key--)
		push_pa(b_list, a_list);
	if ((*a_list)->nbr > (*a_list)->next->nbr)
		sa_swap(a_list);
}
