/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:31:09 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/21 19:34:13 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_node	*ft_last(t_node *lst)
{
	t_node	*aux;

	aux = lst;
	if (!lst)
		return (NULL);
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	ft_add_back(t_node **lst, t_node *new)
{
	t_node	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		aux = ft_last(*lst);
		aux->next = new;
	}
}
