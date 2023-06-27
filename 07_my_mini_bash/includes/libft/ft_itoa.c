/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:22:59 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/06/12 15:22:40 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nbr;

	len = ft_size(n);
	nbr = malloc(sizeof(char) * len + 1);
	if (!nbr || !len)
		return (NULL);
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
		nbr[0] = '-';
	while (n)
	{
		len--;
		nbr[len] = ft_sign(n % 10) + '0';
		n = n / 10;
	}
	return (nbr);
}
