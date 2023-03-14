/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:58:49 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/14 19:33:12 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb(char **str, t_stack *data)
{
	int	i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '-')
			j = 1;
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return(0);
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

int check_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strncmp(str[i], str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
char	*join_arg(char **s)
{
	int i;
	char *str;

	i = 1;
	str = ft_strdup("");
	while (s[i])
	{
		str = ft_strjoin(str," ");
		str = ft_strjoin(str, s[i]);
		i++;
	}
	return (str);
}

int	*parse_data(char **str)
{
	int i;
	int *tab;
	i = -1;
	while(str[++i]);
	tab = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (str[++i])
	{
		tab[i] = ft_atoi(str[i]);
	}
	return (tab);
}
int main(int argc, char **argv)
{
	char *s;
	t_stack data;
	char **str;
	int i;
	int j;

	j = 0;

	i = 0;
	s = ft_strdup("");
	if (argc > 2)
	{
		data.size_a = 0; 
		data.size_b = 0;
		s = join_arg (argv);
		str = ft_split(s, ' ');
		if (!check_nb(str, &data))
		{
			puts("error");
			exit(1);	
		}
		if (!check_duplicate(str))
		{
			puts("error");
			exit(1);
		}
		data.stack_a = parse_data(str);
		sorted (&data);
		sorting(&data);
		// sorted (&data);
		// pb(&data, 0);
		// pb(&data, 0);
		// pb(&data, 0);
		// rrb(&data, 0);
		// while (j < data.size_a)
		// {
		// 	printf("%d\n",data.stack_a[j]);
		// 	j++;
		// }
		// j = 0;
		// printf("---------------------\n");
		// while (j < data.size_b)
		// {
		// 	printf("%d\n",data.stack_b[j]);
		// 	j++;
		// }
		free (s);
	}
}