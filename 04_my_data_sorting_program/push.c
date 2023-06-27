/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:39:18 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/23 15:19:54 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*aux;

	if (*src != NULL)
	{
		aux = *src;
		*src = aux->next;
		aux->next = *dest;
		*dest = aux;
	}
}

void	push_pb(t_node **a_list, t_node **b_list)
{
	push(a_list, b_list);
	write(1, "pb\n", 3);
}

void	push_pa(t_node **b_list, t_node **a_list)
{
	push(b_list, a_list);
	write(1, "pa\n", 3);
}
