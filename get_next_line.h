/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:55:18 by slucas            #+#    #+#             */
/*   Updated: 2022/04/05 06:49:11 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//# define BUFFER_SIZE 4096
//# define BUFFER_SIZE 10

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*get_next_line(int fd);

#endif
