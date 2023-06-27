/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:26:48 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/22 15:40:11 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	start_struct(t_input *ipt);

void	init_shell(t_input *ipt)
{
	if (!start_struct(ipt))
		ft_exit(ipt, 0, 1);
	ft_pipeorg(ipt);
}

static int	start_struct(t_input *ipt)
{
	ipt->token = split_words_quotes(ipt->input, 0, 0, 0);
	if (!ipt->token)
		return (0);
	ft_parse(ipt, 0);
	split_clean(&ipt->token);
	return (1);
}

void	call_commands(t_input *ipt, t_commands *cmmd)
{
	if (is_command(cmmd) == 1)
		ft_echo(cmmd);
	else if (is_command(cmmd) == 2)
		ft_cd(ipt, cmmd);
	else if (is_command(cmmd) == 3)
		ft_pwd(ipt->envp);
	else if (is_command(cmmd) == 4)
		call_export(ipt, cmmd);
	else if (is_command(cmmd) == 5)
		call_unset(ipt, cmmd);
	else if (is_command(cmmd) == 6)
	{
		if (cmmd && !cmmd->command[1])
			print_envp(ipt);
		else
		{
			g_ret = 127;
			ft_fprintf(2, "env: %s: No such file or directory\n", \
			cmmd->command[1]);
		}
	}	
	else if (is_command(cmmd) == 7)
		ft_exit(ipt, cmmd, 0);
}
