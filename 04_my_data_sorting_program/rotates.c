/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:37 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:10 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **lst)
{
	t_node	*old_bottom;
	t_node	*new_bottom;

	if ((*lst)->next != NULL)
	{
		old_bottom = *lst;
		while (old_bottom->next != NULL)
			old_bottom = old_bottom->next;
		new_bottom = *lst;
		*lst = (*lst)->next;
		new_bottom->next = NULL;
		old_bottom->next = new_bottom;
	}
}

void	rotate_ra(t_node **a_list)
{
	rotate(a_list);
	write(1, "ra\n", 3);
}

void	rotate_rb(t_node **b_list)
{
	rotate(b_list);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_node **a_list, t_node **b_list)
{
	rotate(a_list);
	rotate(b_list);
	write(1, "rr\n", 4);
}
