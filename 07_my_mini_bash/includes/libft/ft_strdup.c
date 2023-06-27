/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:23:49 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/16 19:35:01 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1 ;
	copy = malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}
