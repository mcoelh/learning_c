/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:28:28 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/22 17:40:23 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
