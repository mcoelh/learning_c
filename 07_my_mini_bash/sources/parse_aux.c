/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:13:08 by matanton          #+#    #+#             */
/*   Updated: 2023/05/23 21:18:09 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmdadd_back(t_commands **lst, t_commands *node)
{
	t_commands	*last;

	last = *lst;
	if (last)
		while (last->next)
			last = last->next;
	if (!last)
		*lst = node;
	else
		last->next = node;
}

void	parse_aux(t_input *ipt, int *i)
{
	ipt->quote = 0;
	if (find_quotes(ipt->token[*i], ipt))
	{
		ipt->token[*i] = take_quotes(ipt->token[*i], &ipt->quote);
		ipt->quote = 0;
	}
	*i += 1;
}
