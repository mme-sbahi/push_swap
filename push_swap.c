/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:58:49 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/21 17:01:20 by mmesbahi         ###   ########.fr       */
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

void	parse_data(char **str, t_stack *data)
{
	int i;
	i = -1;
	while(str[++i]);
	data->size_a = i;
	data->stack_a = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (str[++i])
	{
		data->stack_a[i] = ft_atoi(str[i]);
	}
}

void	parsing(char **av, t_stack *data)
{
	char *s;
	char **str;
	int i;
	int j;

	j = 0;

	i = 0;
	s = ft_strdup("");
	data->size_a = 0; 
	data->size_b = 0;
	data->pos = -1;
	s = join_arg (av);
	str = ft_split(s, ' ');
	if (!check_nb(str, data))
	{
		puts("error");
		exit(1);	
	}
	if (!check_duplicate(str))
	{
		puts("error");
		exit(1);
	}
	parse_data(str, data);
	if (!sorted(data))
		exit(0);
	free (s);
}
  
int main(int argc, char **argv)
{
	t_stack data;
	int i;

	i = 0;
	if (argc > 2)
	{
			parsing(argv, &data);
			//indexing
			// pb(&data,0);
			if (data.size_a > 5)
				sort_100(&data);
			else
				sorting(&data);
			// int i = 0;
			// while (i < data.size_b)
			// 	printf ("%d\n", data.stack_b[i++]);
			// sort_over_100(&data);
			// while (i < data.size_a)
			// {
			// 	printf("-->%d  ",data.stack_a[i]);
			// 	i++;
			// }
			// i = 0;
	}
}