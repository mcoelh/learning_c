/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:58:57 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:07:43 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	b;
	size_t	l;
	char	*p_big;

	b = 0;
	l = 0;
	p_big = (char *) big;
	if (little[0] == '\0')
		return (p_big);
	while (big[b] != '\0')
	{
		if (little[l] == big[b + l] && b + l < n)
			while (little[l] == big[b + l] && little[l] != '\0')
				l++;
		if (little[l] == '\0')
			return (&p_big[b]);
		b++;
	}
	return (0);
}
