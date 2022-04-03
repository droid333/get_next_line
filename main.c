/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:58 by slucas            #+#    #+#             */
/*   Updated: 2022/04/03 03:32:02 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd; // return un int

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}

	//printf("fd: %d\n", fd);
	//printf("get: %s\n", get_next_line(fd));
	//printf("get: %s\n", get_next_line(fd));

	char	*line;
	int	i = 1;
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}

	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}

