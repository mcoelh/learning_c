/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:37 by matanton          #+#    #+#             */
/*   Updated: 2023/05/23 20:39:27 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*expand_envp_aux(char *aux, t_input *ipt, char *ret, int *i)
{
	char	*env;

	env = NULL;
	while (*(ipt->envp + *i))
	{
		env = *(ipt->envp + *i);
		if (!ft_strncmp(aux + 1, env, ft_strlen(aux + 1)))
		{
			if (*(env + ft_strlen(aux + 1)) == '=')
			{
				ret = ft_strdup((env + (ft_strlen(aux + 1) + 1)));
				break ;
			}
		}
		*i += 1;
	}
	return (ret);
}

static char	*expand_envp(char *aux, t_input *ipt, char *ret)
{
	int	i;

	i = 0;
	if (aux[0] == '\"')
		aux = del_quote(aux, '\"', NULL);
	if (!ft_isalpha(aux[i + 1]) && aux[1] != '_' )
	{
		if (aux[i + 1] == '?')
			ret = ft_itoa(g_ret);
		else if (aux[i + 1] == '$')
			ret = 0;
		else
			return (aux);
	}
	else
		ret = expand_envp_aux(aux, ipt, ret, &i);
	if (ret == NULL)
		ret = ft_strdup("");
	free (aux);
	return (ret);
}

char	*check_expand(char *str, t_input *ipt, char *aux, char *ret)
{
	int		i;
	char	*temp;

	temp = NULL;
	while (*str != '\0')
	{
		i = 0;
		check_quotes(str, &i, &ipt->quote);
		if (!check_var_expand(str, ipt, &i))
			while (((str[i] != '$') || (str[i] == '$' && ipt->quote == '\'')) \
			&& !check_quotes(str, &i, &ipt->quote) && (str[i]))
				i++;
		aux = ft_substr(str, 0, i);
		str += i;
		if (ipt->quote != '\'' && aux[0] != '\'')
			if (((aux[0] == '\"' && aux[1] == '$') || aux[0] == '$'))
				aux = expand_envp(aux, ipt, NULL);
		temp = ft_strjoin(ret, aux);
		free(ret);
		free(aux);
		ret = temp;
	}
	return (ret);
}

void	expand(t_input *ipt, int i)
{
	char	*aux;

	aux = NULL;
	ipt->quote = 0;
	if (!ipt->token[i] || ipt->token[i] == NULL)
		return ;
	aux = check_expand(ipt->token[i], ipt, NULL, NULL);
	if (!aux)
		aux = ft_strdup("");
	free(ipt->token[i]);
	ipt->token[i] = aux;
}
