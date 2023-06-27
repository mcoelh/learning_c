/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:38:33 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:04:13 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	srclen;
	size_t	destlen;
	size_t	max;

	count = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	max = size - destlen - 1;
	if (size <= destlen)
		return (size + srclen);
	while (src[count] && destlen + 1 < size && count < max)
	{
		dst[destlen + count] = src[count];
		count++;
	}
	dst[destlen + count] = '\0';
	return (destlen + srclen);
}
