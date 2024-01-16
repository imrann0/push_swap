/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:18:37 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 13:16:40 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include "Libfth/libft.h"

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (create_line == 1)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}

char	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	res = 0;
	if (!stash && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(stash, buf);
	ft_free_stash(&stash, 0);
	return (res);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_stash(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	res = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!res)
	{
		ft_free_stash(&stash, 0);
		return (NULL);
	}
	ft_free_stash(&stash, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		byte;
	static char	*stash = NULL;
	char		*line;

	line = 0;
	byte = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stash(&stash, 0));
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if ((byte <= 0 && !stash) || byte == -1)
			return (ft_free_stash(&stash, 0));
		buf[byte] = '\0';
		stash = ft_copy_to_stash(stash, buf);
		if (ft_strchr(stash, '\n') != NULL)
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}
