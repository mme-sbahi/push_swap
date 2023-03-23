/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:05:30 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:41 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*l;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	l = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!l)
		return (NULL);
	while (s1[++i])
		l[i] = s1[i];
	while (s2[j])
		l[i++] = s2[j++];
	return (l[i] = '\0', free(s1), l);
}
