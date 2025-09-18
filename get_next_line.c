/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:39:12 by rida-cos          #+#    #+#             */
/*   Updated: 2025/09/17 23:57:59 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*read_file(char *buffer, int fd)
{
	ssize_t	bytes;
	char	*temp_buffer;	
	char	*new_buffer;

	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		temp_buffer = malloc(BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (0);
		bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(temp_buffer);
			if (bytes == -1)
				return (NULL);
			break ;
		}
		temp_buffer[bytes] = '\0';
		new_buffer = ft_strjoin(buffer, temp_buffer);
		free(temp_buffer);
		free(buffer);
		buffer = new_buffer;
		if (!buffer)
			return (0);
	}
	return (buffer);
}

static char	*update_buffer(char *buffer, char **line)
{
	char	*next_line_pos;
	char	*new_buffer;

	if (buffer[0] == '\0')
	{
		free(buffer);
		*line = NULL;
		return (NULL);
	}
	next_line_pos = ft_strchr(buffer, '\n');
	if (!next_line_pos)
	{
		*line = ft_strdup(buffer);
		free(buffer);
		return (0);
	}
	*line = ft_substr(buffer, 0, next_line_pos - buffer + 1);
	if (ft_strlen(next_line_pos + 1) == 0)
	{
		free(buffer);
		return (0);
	}
	new_buffer = ft_strdup(next_line_pos + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (0);
	}
	buffer = read_file(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	buffer = update_buffer(buffer, &line);
	if (!line)
		return (NULL);
	return (line);
}

// # include <fcntl.h>

// int	main(void)
// {
// 	const char	*path;
// 	char		*line;
// 	int			fd;

// 	path = "gnl1.txt";
// 	fd = open(path, O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("Line 1:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 2:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 3:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 4:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 5:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 6:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 7:%s", line);
// 	line = get_next_line(fd);
// 	printf("Line 8:%s", line);
// 	close(fd);
// }
