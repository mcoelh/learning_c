/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:21:17 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/13 17:02:10 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, char const *src1, char const *src2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*temp;
	int		s1len;
	int		s2len;
	int		lensfinal;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	lensfinal = s1len + s2len + 1;
	s3 = malloc(lensfinal * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	temp = ft_strcpy(s3, s1, s2);
	return (temp);
}

static char	*ft_strcpy(char *dst, char const *src1, char const *src2)
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
	while (src2[count_j] != '\0')
	{
		dst[count_i + count_j] = src2[count_j];
		count_j++;
	}
	dst[count_i + count_j] = '\0';
	return (dst);
}
