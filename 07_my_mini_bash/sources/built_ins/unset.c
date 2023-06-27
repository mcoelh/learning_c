/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:36 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 15:40:38 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_unset(char *str, t_input *ipt);
static void	del_var(char *str, t_input *ipt);

void	call_unset(t_input *ipt, t_commands *cmmd)
{
	int	i;

	i = 1;
	g_ret = 0;
	while (cmmd->command[i])
	{
		if (!ft_isalpha(cmmd->command[i][0]) && cmmd->command[i][0] != '_')
		{
			g_ret = 1;
			ft_fprintf(2, "unset: %s: not a valid identifier\n", \
			cmmd->command[i]);
			break ;
		}
		if (check_unset(cmmd->command[i], ipt))
			del_var(cmmd->command[i], ipt);
		i++;
	}
}

static int	check_unset(char *str, t_input *ipt)
{
	int	i;

	i = 0;
	while (ipt->envp[i])
	{
		if (!ft_strncmp(str, ipt->envp[i], ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

static void	del_var(char *str, t_input *ipt)
{
	int	i;
	int	j;

	i = 0;
	while (ipt->envp[i])
	{
		if (!ft_strncmp(str, ipt->envp[i], ft_strlen(str)))
			break ;
		i++;
	}
	while (ipt->envp[i])
	{
		j = i + 1;
		free(ipt->envp[i]);
		ipt->envp[i] = NULL;
		if (ipt->envp[j])
			ipt->envp[i] = ft_strdup(ipt->envp[j]);
		i++;
	}
}
