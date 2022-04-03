/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:58:22 by slucas            #+#    #+#             */
/*   Updated: 2022/04/03 03:37:44 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(const char *tmp_str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!tmp_str)
	//if (!tmp_str[i])
		return (NULL);
	while (tmp_str[i] && tmp_str[i] != '\n')
		i++;
	if (tmp_str[i] == '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = tmp_str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

/*
** line55 is for the EOF (if)
** line63 is for the '\n' (i++)
*/
char	*ft_get_rest(char *tmp_str)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	while (tmp_str[i] && tmp_str[i] != '\n')
		i++;
	if (!tmp_str[i])
	{
		free(tmp_str);
		return (NULL);
	}
	rest = malloc(sizeof(*rest) * (ft_strlen(tmp_str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (tmp_str[i])
		rest[j++] = tmp_str[i++];
	rest[j] = '\0';
	free(tmp_str);
	return (rest);
}

char	*ft_get_tmp_str(int fd, char *tmp_str)
{
	char	*buffer;
	int		rd_ret;

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd_ret = 1;
	while (!ft_strchr(tmp_str, '\n') && rd_ret != 0)
	{
		rd_ret = read(fd, buffer, BUFFER_SIZE);
		if (rd_ret == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rd_ret] = '\0';
		tmp_str = ft_strjoin(tmp_str, buffer);
	}
	free(buffer);
	return (tmp_str);
}

char	*get_next_line(int fd)
{
	static char	*tmp_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp_str = ft_get_tmp_str(fd, tmp_str);
	if (!tmp_str)
		return (NULL);
	line = ft_get_line(tmp_str);
	tmp_str = ft_get_rest(tmp_str);
	return (line);
}
