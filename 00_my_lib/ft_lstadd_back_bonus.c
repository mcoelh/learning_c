/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:02:23 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/07 17:08:39 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}
