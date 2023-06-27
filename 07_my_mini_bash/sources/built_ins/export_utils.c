/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:37:41 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 17:36:54 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_var_value(char *str);

int	check_export(char *str)
{
	int		i;
	char	*equal;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	equal = ft_strchr(str, '=');
	if (!equal)
		return (0);
	while (i < equal - str)
	{
		if ((ft_isalnum(str[i]) == 0) && (str[i] != '_'))
			return (0);
		i++;
	}
	if (!check_var_value(equal + 1))
		return (0);
	return (1);
}

static int	is_special(char c)
{
	if (!(c == '!' || c == '#' || c == '%' || c == '<' \
		|| c == ':' || (c >= 40 && c <= 47) \
		|| (c >= 62 && c <= 64) || (c >= 91 && c <= 94) \
		|| (c >= 123 && c < 127) || (c == '=') || (c == '_') || (c == ' ')))
		return (0);
	return (1);
}

static int	check_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && !is_special(str[i]))
			return (0);
		i++;
	}
	return (1);
}
