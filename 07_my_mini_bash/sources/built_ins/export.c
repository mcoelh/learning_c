/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:57:23 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 19:39:16 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_temp(char **temp);
static int	check_var(char *str, t_input *ipt);
static void	change_var(char *str, t_input *ipt);
static void	add_var(char *str, t_input *ipt);

void	call_export(t_input *ipt, t_commands *cmmd)
{
	int	i;

	i = 1;
	while (cmmd->command[i])
	{
		if (!check_export(cmmd->command[i]))
		{
			g_ret = 1;
			ft_fprintf(2, "export: %s: not a valid identifier\n", \
			cmmd->command[i]);
		}
		else
		{
			if (check_var(cmmd->command[i], ipt))
				change_var(cmmd->command[i], ipt);
			else
				add_var(cmmd->command[i], ipt);
		}
		i++;
	}
}

/*checa se essa var existe na env ou não*/
static int	check_var(char *str, t_input *ipt)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '=')
		i++;
	len = i + 1;
	i = 0;
	while (ipt->envp[i])
	{
		if (!ft_strncmp(str, ipt->envp[i], len))
			return (1);
		i++;
	}
	return (0);
}

static void	change_var(char *str, t_input *ipt)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len] != '=')
		len++;
	len += 1;
	while (ipt->envp[i])
	{
		if (!ft_strncmp(str, ipt->envp[i], len))
		{
			free(ipt->envp[i]);
			ipt->envp[i] = NULL;
			ipt->envp[i] = ft_strdup(str);
			break ;
		}
		i++;
	}
}

static void	add_var(char *str, t_input *ipt)
{
	int		i;
	int		size;
	char	**temp;

	i = 0;
	size = 0;
	while (ipt->envp[size])
		size++;
	temp = (char **)malloc(sizeof(*temp) * (size + 2));
	while (ipt->envp[i])
	{
		temp[i] = ft_strdup(ipt->envp[i]);
		free(ipt->envp[i]);
		i++;
	}
	temp[i] = ft_strdup(str);
	temp[i + 1] = NULL;
	free(ipt->envp);
	ipt->envp = NULL;
	ipt->envp = get_envp(temp, ipt);
	free_temp(temp);
}

static void	free_temp(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}
