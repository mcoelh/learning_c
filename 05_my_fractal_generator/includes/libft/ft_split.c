/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:20:47 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/13 17:00:29 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i - 1] == c || i == 0))
			words++;
		i++;
	}
	return (words);
}

static int	ft_len(char const *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c && str[count] != '\0')
	count++;
	return (count);
}

static char	*ft_copy(char const *s, char c)
{
	int		i;
	int		count;
	char	*copy;

	i = 0;
	count = 0;
	while (s[count] != '\0' && s[count] != c)
	count++;
	copy = malloc(sizeof(char) * (count + 1));
	if (!copy)
		return (NULL);
	while (i < count)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		t;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!split)
		return (NULL);
	while (j < ft_counter(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		t = ft_len(&s[i], c);
		split[j] = ft_copy(s + i, c);
		j++;
		i = i + ft_len(&s[i], c);
	}
	split[j] = NULL;
	return (split);
}
