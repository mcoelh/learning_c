/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:49:55 by matanton          #+#    #+#             */
/*   Updated: 2023/05/23 21:34:18 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_size(char *str, char *quote)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == *quote)
			{
				*quote = 0;
				i++;
			}
			else if (!*quote)
			{
				*quote = str[i];
				i++;
			}
		}
		i++;
		size++;
	}
	return (size);
}

int	check_unique_quote(char *str, int i, char *quote)
{
	if (str[i] == '\'' || str[i] == '\"')
	{
		if (str[i] == *quote)
		{
			*quote = 0;
			return (1);
		}
		else if (!*quote)
		{
			*quote = str[i];
			return (1);
		}
	}
	return (0);
}

char	*take_quotes(char *input, char *quote)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (count_size(input, quote) + 1));
	if (!ret)
		ret = NULL;
	*quote = 0;
	while (input[j] != '\0')
	{
		if (!check_unique_quote(input, j, quote))
		{
			ret[i] = input[j];
			i++;
		}
		j++;
	}
	ret[i] = '\0';
	free(input);
	return (ret);
}

int	find_quotes(char *str, t_input *ipt)
{
	int	i;

	i = 0;
	ipt->quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !ipt->quote)
			return (1);
		i++;
	}
	return (0);
}
