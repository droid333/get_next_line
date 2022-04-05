/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:58 by slucas            #+#    #+#             */
/*   Updated: 2022/04/05 07:07:28 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	fd; // return un int
	int fd1;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	fd1 = open("test1.txt", O_RDONLY);

	//printf("fd: %d\n", fd);
	//printf("get: %s\n", get_next_line(fd));
	//printf("get: %s\n", get_next_line(fd));

	char	*line;
	//char	*line1;
	int	i = 1;
	while (i < 15)
	{
		line = get_next_line(fd);
		//line1 = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		//printf("line1 [%02d]: %s", i, line1);
		free(line);
		//free(line1);
		line = get_next_line(fd1);
		printf("line1 [%02d]: %s", i, line);
		free(line);
		i++;
	}

	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	close(fd1);
	return (0);
}

