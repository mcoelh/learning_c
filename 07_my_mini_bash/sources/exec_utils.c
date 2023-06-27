/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:21:42 by matanton          #+#    #+#             */
/*   Updated: 2023/05/23 21:01:11 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*create_path(char **paths, char *cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	path = NULL;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		else
		{
			free(path);
			path = NULL;
			i++;
		}
	}
	return (path);
}

char	*getpath(char **envp, char *cmd, char *path, char **paths)
{	
	int		i;

	i = -1;
	if (!cmd)
	{
		g_ret = 127;
		ft_fprintf(2, "Minishell: : command not found\n");
		return (cmd);
	}
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			path = create_path(paths, cmd);
		}
	}
	split_clean(&paths);
	if (path && access(path, F_OK | X_OK) == 0)
		return (path);
	g_ret = 127;
	ft_fprintf(2, "Minishell: %s: command not found\n", cmd);
	return (NULL);
}

int	ft_cmmd(t_input *ipt, t_commands *cmmd)
{
	char	*pathname;

	pathname = getpath(ipt->envp, cmmd->command[0], NULL, NULL);
	if (pathname == NULL || !pathname)
	{
		free(ipt->input);
		split_clean(&ipt->token);
		free_list(&ipt->commands);
		split_clean(&ipt->envp);
		clear_history();
		exit (127);
	}
	execve(pathname, cmmd->command, ipt->envp);
	return (0);
}

t_pid	*msh_pidnew(int pid)
{
	t_pid	*node;

	node = ft_calloc(sizeof(t_pid), 1);
	if (node)
		node->pd = pid;
	return (node);
}

void	msh_pidadd_back(t_pid **list, t_pid *node)
{
	t_pid	*lst;

	lst = *list;
	if (lst)
		while (lst->next)
			lst = lst->next;
	if (!lst)
		*list = node;
	else
		lst->next = node;
}
