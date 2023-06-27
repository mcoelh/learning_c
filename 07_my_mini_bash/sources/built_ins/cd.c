/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:50 by matanton          #+#    #+#             */
/*   Updated: 2023/05/22 15:41:35 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	change_new(char *str, t_input *ipt);
static void	change_old(char *str, t_input *ipt);

static void	old_to_new(t_input *ipt)
{
	int		i;
	char	*old;
	char	*new;

	i = 0;
	old = NULL;
	new = (char *)getcwd(NULL, 0);
	while (ipt->envp[i])
	{
		if (!ft_strncmp(ipt->envp[i], "PWD=", ft_strlen("PWD=")))
		{
			old = ft_strdup(ipt->envp[i] + 4);
			break ;
		}
		i++;
	}
	change_old(old, ipt);
	change_new(new, ipt);
	free(old);
	free(new);
}

static void	change_old(char *str, t_input *ipt)
{
	int		i;
	char	*aux;
	char	*old;

	i = 0;
	aux = ft_strdup("OLDPWD=");
	old = ft_strjoin(aux, str);
	while (ipt->envp[i])
	{
		if (!ft_strncmp(ipt->envp[i], aux, ft_strlen(aux)))
		{
			free(ipt->envp[i]);
			ipt->envp[i] = NULL;
			ipt->envp[i] = ft_strdup(old);
		}
		i++;
	}
	free(aux);
	free(old);
}

static void	change_new(char *str, t_input *ipt)
{
	int		i;
	char	*aux;
	char	*new;

	i = 0;
	aux = ft_strdup("PWD=");
	new = ft_strjoin(aux, str);
	while (ipt->envp[i])
	{
		if (!ft_strncmp(ipt->envp[i], aux, ft_strlen(aux)))
		{
			free(ipt->envp[i]);
			ipt->envp[i] = NULL;
			ipt->envp[i] = ft_strdup(new);
			break ;
		}
		i++;
	}
	free(aux);
	free(new);
}

static char	*get_home(t_input *ipt)
{
	int		i;
	char	**str;
	char	*home;

	i = 0;
	str = NULL;
	if (!ipt)
		return (NULL);
	while (ipt->envp[i])
	{
		if (!ft_strncmp("HOME=", ipt->envp[i], 5))
		{
			str = ft_split(ipt->envp[i], '=');
			break ;
		}
		i++;
	}
	if (str == NULL)
		return (NULL);
	else
		home = str[1];
	return (home);
}

void	ft_cd(t_input *ipt, t_commands *cmmd)
{
	g_ret = 0;
	if (!cmmd->command[1])
	{
		if (!get_home(ipt))
		{
			ft_fprintf(2, "Minishell: cd: HOME not set\n");
			g_ret = 1;
			return ;
		}
		chdir(get_home(ipt));
		old_to_new(ipt);
		return ;
	}
	g_ret = 1;
	if (!chdir(cmmd->command[1]))
	{
		old_to_new(ipt);
		return ;
	}
	ft_fprintf(2, "Minishell: cd: %s: %s\n", cmmd->command[1], strerror(errno));
	return ;
}
