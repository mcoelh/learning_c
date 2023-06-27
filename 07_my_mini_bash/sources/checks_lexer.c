/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:52:15 by matanton          #+#    #+#             */
/*   Updated: 2023/05/18 16:36:54 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_printerror(int a, char c, char *junk)
{
	if (a == 1)
		ft_fprintf(2, "Minishell: syntax error near unexpected token \'%c\'\n", c);
	free(junk);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
		c == '\r')
		return (1);
	else
		return (0);
}

int	check_closedop(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (flag == 0)
				flag = '\'';
			else if (flag == '\'')
				flag = 0;
		}
		if (str[i] == '\"')
		{
			if (flag == 0)
				flag = '\"';
			else if (flag == '\"')
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int	check_pipe(char *line)
{
	int		i;
	char	*new;

	new = NULL;
	new = ft_strtrim(line, " \t\v\n\f\r");
	i = ft_strlen(new);
	if (new[0] == '|' || new[i - 1] == '|')
		return (ft_printerror(1, '|', new));
	i = 0;
	while (new[i])
	{
		i += jump_quote(new + i);
		if (new[i] == '|')
		{
			i++;
			while (ft_isspace(new[i]))
				i++;
			if (new[i] == '|')
				return (ft_printerror(1, '|', new));
		}
		else if (new[i])
			i++;
	}
	free(new);
	return (1);
}

int	check_redirect(char *line, int i, char opt)
{
	while (line[i])
	{
		i += jump_quote(line + i);
		if (line[i] == '>' || line[i] == '<')
		{
			opt = line[i];
			if (line[++i] == opt)
				if (line[++i] == opt)
					return (ft_printerror(1, opt, NULL));
			while (ft_isspace(line[i]))
				i++;
			if (jump_quote(line + i))
				i += jump_quote(line + i);
			else
			{
				if (!line[i] || ft_strchr("<>|", line[i]))
					return (ft_printerror(1, '>', NULL));
				while (line[i] && !ft_strchr("<>\'\"", line[i]))
					i++;
			}
		}
		else if (line[i])
			i++;
	}
	return (1);
}
