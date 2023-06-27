/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:05 by matanton          #+#    #+#             */
/*   Updated: 2023/05/22 18:59:59 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lastpipeaux(t_pid *aux)
{
	int	ret;

	ret = 0;
	waitpid(aux->pd, &ret, 0);
	if (WIFEXITED(ret))
		g_ret = WEXITSTATUS(ret);
	if (WIFSIGNALED(ret))
		g_ret = 128 + WTERMSIG(ret);
}
