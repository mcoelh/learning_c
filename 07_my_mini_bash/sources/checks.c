/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:30:15 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/18 23:41:26 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	call_builtin(t_input *ipt)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	if (ipt->commands->fd_in > 0)
	{
		dup2(ipt->commands->fd_in, 0);
		close(ipt->commands->fd_in);
	}
	if (ipt->commands->fd_out > 0)
	{
		dup2(ipt->commands->fd_out, 1);
		close(ipt->commands->fd_out);
	}
	call_commands(ipt, ipt->commands);
	dup2(in, 0);
	close(in);
	dup2(out, 1);
	close(out);
}

int	is_command(t_commands *cmmd)
{
	if (!cmmd->command)
		return (0);
	if (!ft_strncmp(cmmd->command[0], "echo", 5))
		return (1);
	if (!ft_strncmp(cmmd->command[0], "cd", 3))
		return (2);
	if (!ft_strncmp(cmmd->command[0], "pwd", 4))
		return (3);
	if (!ft_strncmp(cmmd->command[0], "export", 7))
		return (4);
	if (!ft_strncmp(cmmd->command[0], "unset", 6))
		return (5);
	if (!ft_strncmp(cmmd->command[0], "env", 4))
		return (6);
	if (!ft_strncmp(cmmd->command[0], "exit", 5))
		return (7);
	return (0);
}

int	is_operator(char *str)
{
	if (str[0] == '<')
	{
		if (str[1] == '<')
			return (1);
		else
			return (3);
	}
	if (str[0] == '>')
	{
		if (str[1] == '>')
			return (2);
		else
			return (4);
	}
	return (-1);
}

int	jump_quote(char *line)
{
	char	quote;
	int		i;

	i = 0;
	if (*(line + i) == '\'' || *(line + i) == '\"')
	{
		quote = *(line + i++);
		while (*(line + i) && *(line + i) != quote)
			i++;
		if (*(line + i))
			i++;
		if (!*(line + i - 1))
			return (666);
	}
	return (i);
}

int	check_lexer(char *arg)
{
	char	opt;

	opt = check_closedop(arg);
	if (opt)
		return (ft_printerror(0, opt, 0));
	else if (!check_pipe(arg))
		return (0);
	else if (!check_redirect(arg, 0, 0))
		return (0);
	return (1);
}
