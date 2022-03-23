/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:58:22 by slucas            #+#    #+#             */
/*   Updated: 2022/03/23 18:26:02 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_static(void)
{
	static int	count;

	count++;
	return (count);
}

int	ft_isnewline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	int			r_ret; // return le nbre doctets a lire
	static int	offset; // ca bouge
	char		buf[BUFFER_SIZE + 1]; // malloc pour du dynamic
	char		*line;
	int			i;
	int			j;
	
	offset = 0;
	//offset = ft_static();
	//printf("offset: %d\n", offset);
	/*
	printf("r_ret: %d\n", r_ret);
	*/
	i = 0;
	//while (read(fd, buf, BUFFER_SIZE))
	//while (1)
	//{
		r_ret = read(fd, buf, BUFFER_SIZE);		
		//buf[r_ret] = '\0';
		//while (i < BUFFER_SIZE)
		while (i < BUFFER_SIZE && buf[offset] != '\n')
		{
			//buf[r_ret] = '\0';
			//if (buf[offset] == '\n')
			//	break;
			//printf("%c", buf[i]);
			offset = ft_static();
			i++;
		}
	//}
	
	line = malloc(sizeof(*line) * (i + 1));
	j = 0;
	while (i)
	{
		line[j] = buf[j];
		j++;
		i--;
	}
	line[j] = '\0';
	
	return (line);
	//return ("test");
}
