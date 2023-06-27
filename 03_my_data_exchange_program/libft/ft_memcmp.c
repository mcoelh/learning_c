/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:46:22 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:00:25 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*p1;
	unsigned char	*p2;
	int				minus;

	count = 0;
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (count < n)
	{
		minus = p1[count] - p2[count];
		count++;
		if (minus != 0)
			return (minus);
	}
	return (0);
}
