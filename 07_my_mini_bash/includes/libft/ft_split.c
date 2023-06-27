/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:20:47 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/04/20 15:44:44 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (((*(s + 1) == c) || (*(s + 1) == 0)) && (*s != c))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(wc(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (j != i)
			str[k++] = ft_substr(s, j, i - j);
	}
	str[k] = NULL;
	return (str);
}
