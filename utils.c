/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:20 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/13 13:50:03 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = (char *)malloc(i + j + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup( const char *source)
{
	char	*p;
	int		i;

	p = (char *)malloc(ft_strlen(source) + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (source[i])
	{
		p[i] = source[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	sub = malloc (len + 1 * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_strncmp(char *first, char *second)
{
	int	i;

	i = 0;
	while (first[i] && second[i] && first[i] == second[i])
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
long	ft_atoi(const char *str)
{
	long	i;
	long	r;
	long	s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r = r + (str[i] - 48);
		i++;
	}
	return (r * s);
}