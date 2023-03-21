/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:42:10 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/21 18:39:04 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *data)
{
	int	i;
	int	j;
	int	cnt;
    int *tmp;
	
	i = -1;
	j = -1;
	cnt = 0;
	tmp = malloc(sizeof(int) * data->size_a);
	while (++i < data->size_a)
	{
		j = -1;
		while (++j < data->size_a)
			if (i != j && data->stack_a[j] < data->stack_a[i])
				cnt++;
		tmp[i] = cnt;
		cnt = 0;
	}
	free(data->stack_a);
    data->stack_a = tmp;
}

void	ft_search(t_stack *data, int max)
{
	int	i;

	i = 0;
	while (i < data->size_b)
	{
		if (data->stack_b[i] == max )
			break ;
		i++;
	}
	if (i < data->size_b / 2)
		while (i)
		{
			rb(data, 1);
			i--;
		}
	else
	{
		while (i < data->size_b)
		{
			rrb(data, 1);
			i++;
		}
	}
}
int	ft_position(t_stack *data, int val)
{
	int	i;
	
	i = 0;
	while (data->stack_b[i] != val)
		i++;
	return (i);
}  

int	check_instractions(t_stack *data, int max)
{
	int	i;
	
	i = ft_position(data, max);
	if (i < data->size_b / 2)
		return (i);
	else
		return (data->size_b - i);
}
void	f_stackb(t_stack *data)
{
	int	size;
	int tmp;
	int k;
	int num;

	num = 5;
	if (data->check == 1)
		num = 10;
	k = 0;
	size = data->size_a / num;
	tmp = size;
	while (1)
	{
		while (k < tmp)
		{
			if (data->stack_a[0] <= size)
			{
				k++;
				if (data->stack_a[0] <= size - (tmp / 2))
					pb(data, 1);
				else
				{
					pb(data, 1);
					rb(data, 1);
				}
			}
			else
				ra(data, 1);
		}
		if (data->size_a == 0)
			break ;
		k = 0;
		size = size + tmp;
	}
}

void	check_max(t_stack *data, int max)
{
	if (check_instractions(data, max) > check_instractions(data, max - 1) && data->size_b > 1)
	{
			ft_search(data, max - 1);
			pa(data, 1);
			ft_search(data, max);
			pa(data, 1);
			sa(data, 1);
	}
	else if (check_instractions(data, max) <= check_instractions(data, max - 1))
	{
		ft_search(data, max);
		pa(data, 1);
	}
}
		



void	push_to_a(t_stack *data)
{
	int	max;
	int i;

	max = data->size_b - 1;
	i = 0;
	while (i < data->size_b)
	{
		if (data->size_b == 1 && data->stack_b[i] == max)
		{
			pa(data, 1);
		}
		else if (data->stack_b[i] == max)
			check_max(data, max);
		i++;
	}

}


void	sort_100(t_stack *data)
{

	data->check = 0;
	if (data->size_a > 100)
		data->check = 1;
	indexing(data);
	f_stackb(data);
	while (data->size_b)
		push_to_a(data);
}