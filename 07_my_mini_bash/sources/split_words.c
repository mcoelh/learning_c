/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:42:17 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 15:58:37 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_words_quotes(char *str, int i)
{
	int		words;
	int		flag;
	char	quote;

	words = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			flag = 1;
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
			if (str[i])
				flag = 0;
		}
		if ((!ft_strchr(" \n\t\f\v", str[i]) && (ft_strchr(" \n\t\f\v", \
		str[i + 1]) || str[i + 1] == '\0') && (flag == 0)))
			words++;
		i++;
	}
	return (words);
}

int	ft_common_quotes(char *str)
{
	int	i;

	i = 0;
	printf("common str[%s]\n", str);
	while (str[i] && ft_strchr(" \n\t\v\r", str[i]))
		i++;
	while (!ft_strchr(" \n\t\v\r\'\"", str[i]) && str[i])
		i++;
	return (i);
}

int	ft_is_quote42(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	i++;
	while (str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	return (i);
}

char	**split_words_quotes(char *str, int i, int j, int k)
{
	char	**token;
	char	c;

	token = malloc(sizeof(*token) * (count_words_quotes(str, 0) + 1));
	while (str[i] && k < count_words_quotes(str, 0))
	{
		while (str[i] && ft_strchr(" \n\t\v\r", str[i]))
			i++;
		j = i;
		while (str[i] && !ft_strchr(" \n\t\v\r", str[i]))
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				c = str[i];
				i++;
				while (str[i] && str[i] != c)
					i++;
			}
			i++;
		}
		token[k] = ft_substr(str, j, (i - j));
		k++;
	}
	token[k] = NULL;
	return (token);
}
