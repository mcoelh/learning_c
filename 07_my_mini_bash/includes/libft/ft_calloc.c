/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:52:08 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 14:59:31 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;
	size_t	full_size;

	full_size = nelem * elsize;
	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	p = malloc(full_size);
	if (!p)
		return (0);
	ft_bzero(p, full_size);
	return (p);
}
