/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:21:17 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 18:46:11 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strcpy(char *dst, char *src1, char *src2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(char *s);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	char	*temp;
	int		s1len;
	int		s2len;
	int		lensfinal;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	lensfinal = s1len + s2len + 2;
	s3 = malloc(lensfinal * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	temp = ft_strcpy(s3, s1, s2);
	free(s1);
	return (temp);
}

static char	*ft_strcpy(char *dst, char *src1, char *src2)
{
	int	count_i;
	int	count_j;

	count_i = 0;
	count_j = 0;
	while (src1[count_i] != '\0')
	{
		dst[count_i] = src1[count_i];
		count_i++;
	}
	dst[count_i] = ' ';
	count_i++;
	while (src2[count_j] != '\0')
	{
		dst[count_i + count_j] = src2[count_j];
		count_j++;
	}
	dst[count_i + count_j] = '\0';
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1 ;
	copy = malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, len);
	return (copy);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*dest;

	count = 0;
	dest = (char *) dst;
	if (dst == 0 && src == 0)
		return (0);
	while (count < n)
	{
		((char *)dst)[count] = ((char *)src)[count];
		count++;
	}
	return (dest);
}
