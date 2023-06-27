/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:05 by matanton          #+#    #+#             */
/*   Updated: 2023/05/22 19:19:42 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	childpipe_fun(t_commands *cmmd, t_input	*ipt, int *prev, int fd[2])
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close (fd[0]);
	if (cmmd->fd_in)
		dup2(cmmd->fd_in, 0);
	else
		dup2(*prev, 0);
	close(*prev);
	if (cmmd->fd_in)
		close(cmmd->fd_in);
	if (cmmd->fd_out)
		dup2(cmmd->fd_out, 1);
	else
		dup2(fd[1], 1);
	close(fd[1]);
	if (cmmd->fd_out)
		close(cmmd->fd_out);
	if (is_command(cmmd))
	{
		call_commands(ipt, cmmd);
		exit (0);
	}
	else
		ft_cmmd(ipt, cmmd);
}

static void	ft_pipe(t_commands *cmmd, t_input *ipt, int *prev, t_pid **pidlst)
{
	int	fd[2];
	int	pid;

	if (cmmd->fd_in < 0 || cmmd->fd_out < 0)
		return ;
	pipe(fd);
	pid = fork();
	if (!pid)
		childpipe_fun(cmmd, ipt, prev, fd);
	else
	{
		close(*prev);
		*prev = fd[0];
		close(fd[1]);
		msh_pidadd_back(pidlst, msh_pidnew(pid));
	}
}

static void	childlastpipe_fun(t_commands *cmmd, t_input *ipt, int *prev)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (cmmd->fd_in)
		dup2(cmmd->fd_in, 0);
	else
		dup2(*prev, 0);
	close(*prev);
	if (cmmd->fd_in)
		close(cmmd->fd_in);
	if (cmmd->fd_out)
		dup2(cmmd->fd_out, 1);
	if (cmmd->fd_out)
		close(cmmd->fd_out);
	if (is_command(cmmd))
	{
		call_commands(ipt, cmmd);
		exit (0);
	}
	else
		ft_cmmd(ipt, cmmd);
}

void	ft_lastpipe(t_commands *cmmd, t_input *ipt, int *prev, t_pid **pidlst)
{
	int		pid;
	t_pid	*aux;

	if (cmmd->fd_in < 0 || cmmd->fd_out < 0)
		return ;
	pid = fork();
	if (!pid)
		childlastpipe_fun(cmmd, ipt, prev);
	else
	{
		msh_pidadd_back(pidlst, msh_pidnew(pid));
		close(*prev);
		aux = *pidlst;
		while (aux)
		{
			ft_lastpipeaux(aux);
			aux = aux->next;
		}
		free_pid(pidlst);
	}
}

void	ft_pipeorg(t_input	*ipt)
{
	t_commands	*tmp;
	int			prev;
	t_pid		*pid;

	if (ipt->commands == NULL)
		return ;
	if (ipt->commands->next == NULL && is_command(ipt->commands))
		call_builtin(ipt);
	else
	{
		prev = dup(0);
		tmp = ipt->commands;
		pid = NULL;
		while (ipt->commands)
		{	
			if (ipt->commands->next != NULL)
				ft_pipe(ipt->commands, ipt, &prev, &pid);
			else
				ft_lastpipe(ipt->commands, ipt, &prev, &pid);
			ipt->commands = ipt->commands->next;
		}
		ipt->commands = tmp;
	}
}
