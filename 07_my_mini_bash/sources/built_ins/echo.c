/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:51:46 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/16 18:55:24 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_n_flag(char *str);

void	ft_echo(t_commands *cmmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	g_ret = 0;
	while (cmmd->command[i])
	{
		if (check_n_flag(cmmd->command[i]) && i == 1)
		{
			flag = 1;
			while (cmmd->command[i] && check_n_flag(cmmd->command[i]))
				i++;
			if (!cmmd->command[i])
				break ;
		}
		printf("%s", cmmd->command[i]);
		if (cmmd->command[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}

static int	check_n_flag(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
		{
			flag = 1;
			i++;
		}
		while (str[i] == 'n' && flag == 1)
			i++;
		if ((str[i] == 'n' || str[i] == '\0') && flag == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}
