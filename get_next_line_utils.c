/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:02:10 by slucas            #+#    #+#             */
/*   Updated: 2022/04/02 23:17:40 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	while (i <= j)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0x0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	if (s2)
		while (*s2)
			str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
