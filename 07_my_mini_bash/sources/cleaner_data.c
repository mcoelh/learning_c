/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:45:02 by matanton          #+#    #+#             */
/*   Updated: 2023/05/16 20:07:24 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	split_clean(char ***split)
{
	char	**aux;
	int		i;

	if (!split || !*split)
		return ;
	aux = *split;
	i = -1;
	while (*(aux + ++i))
		free (*(aux + i));
	free (aux);
	*split = 0;
}

void	free_list(t_commands **cmmd)
{
	t_commands	*tmp;

	while (*cmmd)
	{
		tmp = (*cmmd)->next;
		split_clean(&(*cmmd)->command);
		if ((**cmmd).fd_in > 0)
			close ((**cmmd).fd_in);
		if ((**cmmd).fd_out > 0)
			close ((**cmmd).fd_out);
		free(*cmmd);
		*cmmd = tmp;
	}
}

void	free_pid(t_pid **pid)
{
	t_pid	*nxt;

	while (*pid)
	{
		nxt = (*pid)->next;
		free(*pid);
		*pid = nxt;
	}
}
