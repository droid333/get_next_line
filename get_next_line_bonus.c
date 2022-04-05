/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:58:22 by slucas            #+#    #+#             */
/*   Updated: 2022/04/05 14:29:45 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** line25 is for the EOF (if)
*/
static char	*ft_get_line(const char *tmp_str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!tmp_str[i])
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
** line57 is for the EOF (if)
** line65 is for the '\n' (i++)
*/
static char	*ft_get_rest(char *tmp_str)
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

/*
** rd = read
** char **tmp_str because static char* in get_next_line
** and just char* here --- lot of problems ( ಠ ʖ̯ ಠ) ---
*/
static void	ft_rd_process(int rd_ret, char *buffer, char **tmp_str)
{
	char	*temp;

	buffer[rd_ret] = '\0';
	temp = *tmp_str;
	if (!temp)
	{
		temp = malloc(sizeof(*temp) * 1);
		temp[0] = '\0';
	}
	*tmp_str = ft_strjoin(temp, buffer);
	free(temp);
}

static char	*ft_get_tmp_str(int fd, char *tmp_str)
{
	char	*buffer;
	int		rd_ret;

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(tmp_str, '\n'))
	{
		rd_ret = read(fd, buffer, BUFFER_SIZE);
		if (rd_ret > 0)
			ft_rd_process(rd_ret, buffer, &tmp_str);
		else
			break ;
	}
	free(buffer);
	if (rd_ret == -1)
		return (NULL);
	return (tmp_str);
}

char	*get_next_line(int fd)
{
	static char	*tmp_str[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	tmp_str[fd] = ft_get_tmp_str(fd, tmp_str[fd]);
	if (!tmp_str[fd])
		return (NULL);
	line = ft_get_line(tmp_str[fd]);
	tmp_str[fd] = ft_get_rest(tmp_str[fd]);
	return (line);
}
