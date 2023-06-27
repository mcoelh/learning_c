/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 05:38:41 by mcoelho-          #+#    #+#             */
/*   Updated: 2022/07/16 20:00:30 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *support);
char	*ft_read(int fd, char *support);
char	*ft_new_support(char *support);

char	*get_next_line(int fd)
{
	static char	*support;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	support = ft_read(fd, support);
	if (!support)
		return (NULL);
	line = ft_line(support);
	support = ft_new_support(support);
	return (line);
}

char	*ft_read(int fd, char *support)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buffer[r] = '\0';
		support = ft_strjoin(support, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (r < 0)
	{
		free(support);
		return (NULL);
	}
	return (support);
}

char	*ft_line(char *support)
{
	char	*line;
	int		j;
	int		size;

	if (support[0] == '\0')
		return (NULL);
	j = 0;
	size = 0;
	while (support[size] != '\0' && support[size] != '\n')
		size++;
	if (support[size] == '\n')
		size++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (j < size)
	{
		line[j] = support[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_new_support(char *support)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = 0;
	if (!support)
		return (NULL);
	while (support[size] != '\0' && support[size] != '\n')
		size++;
	if (support[size] == '\0')
	{
		free(support);
		return (NULL);
	}
	size++;
	new = malloc(sizeof(char) * (ft_strlen(support) - size + 1));
	if (!new)
		return (NULL);
	while (support[size] != '\0')
		new[i++] = support[size++];
	new[i] = '\0';
	free(support);
	return (new);
}
