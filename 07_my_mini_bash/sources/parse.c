/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:13:08 by matanton          #+#    #+#             */
/*   Updated: 2023/05/23 21:33:44 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_openfile(t_commands *cmds, t_input *ipt, int i);

char	**ft_tempjoin(char **src, int start, int end)
{
	char	**dst;
	int		i;
	int		len;

	if (!src || !*src)
		return (0);
	len = 0;
	i = start;
	while (src[i] && i < end)
		if (src[i++][0])
			len++;
	dst = ft_calloc(len + 1, sizeof(char *));
	if (!dst)
		return (0);
	i = 0;
	while (src[start] && start < end)
	{
		if (src[start][0])
			dst[i++] = ft_strdup(src[start]);
		start++;
	}
	dst[i] = 0;
	return (dst);
}

void	ft_parse(t_input *ipt, int i)
{
	int			start;
	t_commands	*cmds;

	cmds = 0;
	while (ipt->token[i] != NULL)
	{
		start = i;
		cmds = ft_calloc(sizeof(t_commands), 1);
		while (ipt->token && ipt->token[i] && ft_strncmp(ipt->token[i], "|", 2))
		{
			expand(ipt, i);
			if (is_operator(ipt->token[i]) > 0 && ipt->token[i + 1])
			{
				ft_openfile(cmds, ipt, i);
				ipt->token[i][0] = '\0';
				ipt->token[++i][0] = '\0';
			}
			else
				parse_aux(ipt, &i);
		}
		cmds->command = ft_tempjoin(ipt->token, start, i);
		cmdadd_back(&ipt->commands, cmds);
		if (ipt->token[i])
			i++;
	}
}

int	clean_buffer(char *line, int fd[2])
{
	int		blen;
	char	jnk[43];

	free(line);
	blen = 0;
	ft_memset(jnk, 0, 43);
	close(fd[1]);
	blen = 1;
	while (blen)
	{
		blen = read(fd[0], jnk, 42);
		*(jnk + blen) = 0;
	}
	return (fd[0]);
}

int	ft_heredoc(char *eof, t_input *ipt)
{
	int		fd[2];
	char	*line;

	pipe(fd);
	line = NULL;
	(void)ipt;
	while (42)
	{
		line = readline(">");
		if (g_ret == 13)
			return (clean_buffer(line, fd));
		if (!line || !ft_strncmp(eof, line, ft_strlen(eof) + 1))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}

static void	ft_openfile(t_commands *cmds, t_input *ipt, int i)
{
	char	*file;

	expand(ipt, i + 1);
	file = ipt->token[i + 1];
	file = ft_strtrim(file, "<> \t\n\v\f\r");
	if (is_operator(ipt->token[i]) == 4)
		cmds->fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (is_operator(ipt->token[i]) == 2)
		cmds->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 00644);
	else if (is_operator(ipt->token[i]) == 3)
		cmds->fd_in = open(file, O_RDONLY);
	else
		cmds->fd_in = ft_heredoc(file, ipt);
	if (cmds->fd_in < 0 || cmds->fd_out < 0)
	{
		g_ret = 1;
		perror(file);
	}
	free(file);
}
