/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:55:23 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/23 20:37:40 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quotes(char *str, int *i, char *quote)
{
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		if (str[*i] == *quote)
		{
			*quote = 0;
			*i += 1;
			return (1);
		}
		else if (!*quote)
		{
			*quote = str[*i];
			if (*i == 0)
				*i += 1;
			return (1);
		}
	}
	return (0);
}

static int	get_size(char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			size++;
		i++;
	}
	return (size);
}

char	*del_quote(char *str, char c, char *ret)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = get_size(str, c);
	ret = malloc(sizeof(char) * size + 1);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	free(str);
	return (ret);
}

static int	var_jump(char *str, int *i, t_input *ipt)
{
	while ((ft_isalnum(str[*i]) || str[*i] == '_'))
		*i += 1;
	if (str[*i] == ipt->quote)
		*i += 1;
	ipt->quote = 0;
	return (1);
}

int	check_var_expand(char *str, t_input *ipt, int *i)
{
	if (str[0] == '\'' || str[0] == '\"')
		ipt->quote = str[0];
	if (ipt->quote != '\'')
	{
		if (str[*i] == '$')
		{
			*i += 1;
			if (!ft_isalpha(str[*i]) && str[*i] != '_')
			{
				if (str[*i] == '$' || str[*i] == '?')
				{
					*i += 1;
					return (1);
				}
				else
					return (0);
			}
			else
				return (var_jump(str, i, ipt));
		}
	}
	return (0);
}
