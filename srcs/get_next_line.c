/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:03:26 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/26 20:01:32 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	size_t		buffer_size_safe;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer_size_safe = BUFFER_SIZE;
	stash = read_buffer(fd, stash, buffer_size_safe);
	if (!stash)
		return (NULL);
	line = fetch_line(stash);
	stash = remove_line_from_stash(stash);
	return (line);
}

char	*read_buffer(int fd, char *stash, size_t buffer_size_safe)
{
	char	*buf;
	int		bytes_read;

	buf = ft_calloc_gnl(sizeof(char), (buffer_size_safe + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (ft_contains_nl(stash) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buf, buffer_size_safe);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = 0;
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (NULL);
	}
	free(buf);
	return (stash);
}

char	*fetch_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = ft_contains_nl(stash);
	if (i == -1)
		i = ft_strlen_gnl(stash);
	else
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line = ft_strlcpy_gnl(line, stash, i + 1);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*remove_line_from_stash(char *stash)
{
	char	*new_stash;
	int		i;
	size_t	len;

	if (!stash)
		return (NULL);
	i = ft_contains_nl(stash) + 1;
	if (i == 0)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen_gnl(stash) - i + 1;
	new_stash = ft_strlcpy_gnl(new_stash, stash + i, len);
	free(stash);
	return (new_stash);
}
