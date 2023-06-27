/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:23:08 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:04 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_node **lst)
{
	t_node	*new_top;
	t_node	*new_bottom;

	if ((*lst)->next != NULL)
	{
		new_bottom = *lst;
		while (new_bottom->next->next != NULL)
			new_bottom = new_bottom->next;
		new_top = *lst;
		while (new_top->next != NULL)
			new_top = new_top->next;
		new_top->next = *lst;
		*lst = new_top;
		new_bottom->next = NULL;
	}
}

void	reverse_rra(t_node **a_list)
{
	reverse(a_list);
	write(1, "rra\n", 4);
}

void	reverse_rrb(t_node **b_list)
{
	reverse(b_list);
	write(1, "rrb\n", 4);
}

void	reverse_rrr(t_node **a_list, t_node **b_list)
{
	reverse(a_list);
	reverse(b_list);
	write(1, "rrr\n", 5);
}
