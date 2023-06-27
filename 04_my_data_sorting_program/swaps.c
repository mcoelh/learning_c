/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:40:21 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:22 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (lst && (*lst)->next)
	{
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		second->next = first;
		*lst = second;
	}
}

void	sa_swap(t_node **a_list)
{
	swap(a_list);
	write(1, "sa\n", 3);
}

void	sb_swap(t_node **b_list)
{
	swap(b_list);
	write(1, "sb\n", 3);
}

void	ss_swap(t_node **a_list, t_node **b_list)
{
	swap(a_list);
	swap(b_list);
	write(1, "ss\n", 3);
}
