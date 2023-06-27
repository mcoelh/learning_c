/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:51:06 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/16 19:10:07 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_envp(char **envp, t_input *ipt)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	g_ret = 0;
	while (envp[len])
		len++;
	ipt->envp = (char **)malloc(sizeof(*ipt->envp) * (len + 1));
	if (!ipt->envp)
		return (NULL);
	while (envp[i] != NULL)
	{
		ipt->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	ipt->envp[i] = NULL;
	return (ipt->envp);
}

void	print_envp(t_input *ipt)
{
	int	i;

	i = 0;
	while (ipt->envp[i])
	{
		printf("%s\n", ipt->envp[i]);
		i++;
	}
}
