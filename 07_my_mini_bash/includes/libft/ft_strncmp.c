/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:30:24 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/16 16:01:37 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*p1;
	unsigned char	*p2;

	count = 0;
	if (!s1 || !s2)
		return (-1);
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while ((p1[count] || p2[count]) && count < n)
	{
		if (p1[count] != p2[count])
			return ((unsigned char)p1[count] - (unsigned char)p2[count]);
		count++;
	}
	return (0);
}
