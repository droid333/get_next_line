/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:58 by slucas            #+#    #+#             */
/*   Updated: 2022/03/23 17:31:47 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int			fd; // return un int

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("fd: %d\n", fd);
	printf("get: %s\n", get_next_line(fd));

	//quand on ne connait pas le nbre d'octets a lire
	//r_ret = read(fd, buf, BUFFER_SIZE);
	// buf : texte sur le nbre doctets lu

	int	i;
	i = 0;
	/*
	while ((r_ret = read(fd, buf, BUFFER_SIZE)))
	//while (buf[i] != '\n')
	{
		buf[r_ret] = '\0';
		//printf("r_ret %d\n", r_ret);
		printf("%s\n", buf);
		//printf("char::: %c\n", buf[i]);
		//i++;
	}
	*/
	/*
	while (r_head < BUFFER_SIZE)
	//while (r_head < BUFFER_SIZE || buf[r_head] != '\n')
	{
		printf("%d\n", r_head);
		printf("%c\n", buf[r_head]);
		printf("%s\n", buf);
		r_head = ft_test();
	}
	*/

	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}

