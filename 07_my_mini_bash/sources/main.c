/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:29:31 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/23 20:59:26 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_ret = 0;

static void	ft_history(char *str)
{
	if (str && *str)
		add_history(str);
}

static int	ft_prompt(t_input *ipt)
{
	char	*arg;

	while (42)
	{
		ipt->input = readline("Minishell:");
		if (ipt->input == NULL)
			ft_exit(ipt, 0, 1);
		ft_history(ipt->input);
		arg = ipt->input;
		while (*arg && ft_strchr(" \t\n\v\f\r", *arg))
			arg++;
		if (*arg && check_lexer(arg))
		{
			init_shell(ipt);
			free_list(&ipt->commands);
		}
		free(ipt->input);
	}
	return (0);
}

void	sig_handler(int sig)
{
	(void)sig;
	if (RL_ISSTATE(RL_STATE_READCMD))
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	else
		printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
	rl_on_new_line();
	g_ret = 13;
}

int	main(int argc, char **argv, char **envp)
{
	t_input	ipt;

	(void)argc;
	(void)argv;
	ft_memset(&ipt, 0, sizeof(t_input));
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, SIG_IGN);
	get_envp(envp, &ipt);
	ft_prompt(&ipt);
	return (0);
}
