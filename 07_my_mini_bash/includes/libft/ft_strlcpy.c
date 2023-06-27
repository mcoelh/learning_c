/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:54:17 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:04:18 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	srclen;

	count = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size > 0)
	{
		while (src[count] != '\0' && count < size -1)
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (srclen);
}
