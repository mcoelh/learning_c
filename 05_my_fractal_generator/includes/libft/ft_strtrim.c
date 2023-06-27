/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:40:09 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/13 17:01:02 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*subs;

	if (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		len = ft_strlen(s1);
		while (len && ft_strchr(set, s1[len]))
			len--;
		subs = ft_substr(s1, 0, len + 1);
		return (subs);
	}
	return (NULL);
}
