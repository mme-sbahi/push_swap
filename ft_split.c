/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:42:03 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/12 13:45:46 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**count_word(const char *str, char set)
{
	int		i;
	int		count;
	char	**c;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != set && (str[i + 1] == set || str[i + 1] == '\0'))
			count++;
		i++;
	}
	c = (char **)malloc ((count + 1) * sizeof(char *));
	if (!c)
		return (NULL);
	return (c);
}

static int	ft_lenght_str(const char *str, char c, int h)
{
	int	len;

	len = 0;
	while (str[h] && str[h] != c)
	{
		h++;
		len++;
	}
	return (len);
}

static char	**ft_free(char **str, int i)
{
	while (i)
	{
		free (str[i]);
		i--;
	}
	free (str);
	return (str);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**splitted;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	splitted = count_word (str, c);
	if (!splitted)
		return (NULL);
	if (str[0] == '\0')
		return (splitted[0] = NULL, splitted);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		splitted[j++] = ft_substr (str, i, ft_lenght_str (str, c, i));
		if (!splitted[j - 1])
			return (ft_free(splitted, j));
		i = i + ft_lenght_str (str, c, i);
	}
	return (splitted[j] = NULL, splitted);
}
