/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:32:46 by matanton          #+#    #+#             */
/*   Updated: 2023/05/18 16:38:22 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exit_is_digit(char *arg)
{
	int	i;

	i = -1;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (255);
	}
	if (!i)
		return (255);
	return (0);
}

static int	ft_take_ret(t_commands *cmmd)
{
	int				i;
	unsigned char	ret;
	char			*arg;

	i = 0;
	while (*(cmmd->command + i))
		i++;
	if (i == 1)
		return (0);
	if (i >= 3)
	{
		ft_fprintf(2, "exit: too many arguments\n");
		return (-1);
	}
	arg = *(cmmd->command + 1);
	ret = exit_is_digit(arg);
	if (ret == 255)
		ft_fprintf(2, "exit: %s: numeric argument required\n", arg);
	else
		ret = ft_atoi(arg);
	return (ret);
}

int	ft_exit(t_input *ipt, t_commands *cmmd, int ret)
{
	int	final;

	if (cmmd)
		final = ft_take_ret(cmmd);
	else
		final = ret;
	if (final < 0)
	{
		g_ret = 1;
		return (1);
	}
	free(ipt->input);
	split_clean(&ipt->token);
	free_list(&ipt->commands);
	split_clean(&ipt->envp);
	clear_history();
	printf("exit\n");
	exit (final);
}
