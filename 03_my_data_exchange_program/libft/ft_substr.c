/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:28:56 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:05:07 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*subs;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start >= len)
		subs = malloc((len + 1) * sizeof(char));
	else
		subs = malloc((slen - start) + 1 * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}
