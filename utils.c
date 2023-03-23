/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:20 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:16:32 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_arr_3(t_stack *data)
{
	if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
		rra(data, 1);
}

void	norm_f_stackb(t_stack *data)
{
	pb(data, 1);
	rb(data, 1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i <= len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
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

int	check_nb(char **str, t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '-' || str[i][0] == '+')
			j = 1;
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (0);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	data->size_a = i;
	return (1);
}
