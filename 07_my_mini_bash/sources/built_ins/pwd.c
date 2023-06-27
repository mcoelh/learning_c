/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:13:56 by matanton          #+#    #+#             */
/*   Updated: 2023/05/20 14:14:44 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(char **envp)
{
	char	*env;
	char	*aux;
	char	*ret;
	int		i;

	aux = "$PWD";
	ret = NULL;
	i = 0;
	while (*(envp + i))
	{
		env = *(envp + i);
		if (!ft_strncmp(aux + 1, env, ft_strlen(aux + 1)))
		{
			if (*(env + ft_strlen(aux + 1)) == '=')
			{
				ret = ft_strdup((env + (ft_strlen(aux + 1) + 1)));
				break ;
			}
		}
		i++;
	}
	ft_fprintf(1, "%s\n", ret);
	return ;
}
