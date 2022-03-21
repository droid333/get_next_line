/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:58 by slucas            #+#    #+#             */
/*   Updated: 2022/03/21 19:36:31 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		r_ret;
	char	buf[BUF_SIZE + 1]; //malloc pour du dynamic

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("open() failed\n");
	printf("fd::: %d\n", fd);
	/*
	r_ret = read(fd, buf, BUF_SIZE);
	buf[r_ret] = '\0';
	printf("r_ret %d\n", r_ret);
	printf("buf:: %s\n", buf);
	*/
	//quand on ne connait pas le nbre d'octets a lire
	while ((r_ret = read(fd, buf, BUF_SIZE)))
	{
		buf[r_ret] = '\0';
		printf("r_ret %d\n", r_ret);
		printf("buf:: %s\n", buf);
	}
	printf("r_ret %d\n", r_ret);

	if (close(fd) == -1)
		printf("close() failed\n");
	return (0);
}

