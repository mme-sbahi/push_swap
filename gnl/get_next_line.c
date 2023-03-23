/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:50:33 by mmesbahi          #+#    #+#             */
/*   Updated: 2022/12/21 01:46:10 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first(char *str)
{
	char	*c;
	int		i;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	c = malloc (i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		c[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		c[i++] = '\n';
	c[i] = '\0';
	return (c);
}

char	*second(char *str)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (ft_strlen(str) == i)
		return (free(str), NULL);
	c = malloc(ft_strlen(str) - i + 1);
	i++;
	while (str[i])
		c[j++] = str[i++];
	c[j] = 0;
	free (str);
	return (c);
}

char	*ft_read_line(int fd, char *s)
{
	char	*ma;
	int		i;

	i = 1;
	ma = malloc (BUFFER_SIZE + 1);
	if (!ma)
		return (NULL);
	while (i && ft_strchr(s, '\n') == 0)
	{
		i = read(fd, ma, BUFFER_SIZE);
		if (i < 0)
			return (free(ma), free(s), NULL);
		ma[i] = '\0';
		s = ft_strjoin(s, ma);
	}
	free (ma);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*sta;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read_line(fd, s);
	if (!s)
		return (NULL);
	sta = first(s);
	s = second(s);
	return (sta);
}
