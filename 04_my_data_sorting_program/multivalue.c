/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multivalue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:32:18 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 19:26:36 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_counter(char *str, char c)
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

static int	ft_len(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c && str[count] != '\0')
	count++;
	return (count);
}

static char	*ft_copy(char *s, char c)
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

static char	**ft_split(char *s, char c)
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
		j ++;
		i = i + t;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_one_arg(int *argc, char **argv)
{
	char	**new_argv;
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	new_argv = ft_split(str, ' ');
	*argc = ft_counter(str, ' ');
	free(str);
	return (new_argv);
}
