/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:20:52 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:00:38 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		count;

	if (len == 0)
		return ((char *)dst);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
				len--;
		}
		return ((char *)dst);
	}
	else if (src > dst)
	{
		count = 0;
		while (count < len)
		{
			((char *)dst)[count] = ((char *)src)[count];
			count++;
		}
		return ((char *)dst);
	}
	return ((char *)dst);
}
