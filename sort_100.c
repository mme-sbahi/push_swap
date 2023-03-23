/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:42:10 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:17:06 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search(t_stack *data, int max)
{
	int	i;

	i = 0;
	while (i < data->size_b)
	{
		if (data->stack_b[i] == max)
			break ;
		i++;
	}
	if (i < data->size_b / 2)
	{
		while (i)
		{
			rb(data, 1);
			i--;
		}
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

void	f_stackb(t_stack *data, int num)
{
	int	size;
	int	tmp;
	int	i;

	// i = 0;
	size = data->size_a / num;
	tmp = size;
	while (data->size_a != 0)
	{
		i = 0;
		while (i < tmp)
		{
			if (data->stack_a[0] <= size)
			{
				i++;
				if (data->stack_a[0] <= size - (tmp / 2))
					pb(data, 1);
				else
					norm_f_stackb(data);
			}
			else
				ra(data, 1);
		}
		size = size + tmp;
	}
}

void	check_max(t_stack *data, int max)
{
	if (check_instractions(data, max) > check_instractions(data, max - 1)
		&& data->size_b > 1)
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
	int	i;

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
		data->check = 10;
	else
		data->check = 5;
	indexing(data);
	f_stackb(data, data->check);
	while (data->size_b)
		push_to_a(data);
}
