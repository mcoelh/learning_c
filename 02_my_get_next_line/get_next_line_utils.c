/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:11 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/07/16 20:08:27 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);

char	*ft_strjoin(char *s1, char *s2)
{
	char		*temp;
	size_t		i;
	size_t		j;

	if (!s1)
		s1 = (ft_strdup(""));
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	temp = malloc(i + j + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, i + 1);
	j = 0;
	while (s2[j])
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}

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

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1 ;
	copy = (char *)malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
