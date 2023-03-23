/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:58:49 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:16:19 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arg(char **s)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	while (s[i])
	{
		str = ft_strjoin (str, " ");
		str = ft_strjoin (str, s[i]);
		i++;
	}
	return (str);
}

void	parse_data(char **str, t_stack *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	data->size_a = i;
	data->stack_a = (int *)malloc (sizeof (int) * i);
	i = -1;
	while (str[++i])
	{
		data->stack_a[i] = ft_atoi(str[i]);
	}
}

void	check_arg(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][0] == '\0')
			ft_error("Error");
		check_esp(tab[i]);
		while (tab[i][j])
		{
			if (tab[i][j] == '+' || tab[i][j] == '-')
			{
				if (!(tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
					ft_error("Error");
			}
			j++;
		}
		i++;
	}
}

void	check_duplicate(t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->size_a)
		{
			if (data->stack_a[i] == data->stack_a[j] && i != j)
				ft_error("Error");
			j++;
		}
		i++;
	}
}

void	parsing(char **av, t_stack *data)
{
	char	*s;
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	check_arg(av);
	s = ft_strdup ("");
	data->size_a = 0;
	data->size_b = 0;
	data->pos = -1;
	s = join_arg (av);
	str = ft_split(s, ' ');
	if (!check_nb(str, data))
		ft_error("error : bad charachters\n");
	parse_data(str, data);
	check_duplicate(data);
	free (s);
}
