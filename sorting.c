/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:57 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 21:02:13 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_stack *data)
{
	int	i;

	i = 1;
	while (i < data->size_a)
	{
		if (data->stack_a[i - 1] > data->stack_a[i])
			return (1);
		i++;
	}
	return (0);
}

void	arr_3(t_stack *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
		sa (data, 1);
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[0] > data->stack_a[2])
		ra(data, 1);
	else if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] < data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
	{
		sa(data, 1);
		ra(data, 1);
	}
	norm_arr_3(data);
}

void	push_to_b(int pos, t_stack *data)
{
	int	j;
	int	i;

	j = data->size_a / 2;
	if (pos < j)
	{
		i = 0;
		while (i < pos)
		{
			ra(data, 1);
			i++;
		}
	}
	if (pos >= j)
	{
		i = pos;
		while (i < data->size_a)
		{
			rra(data, 1);
			i++;
		}
	}
	if (sorted_check(data))
		pb(data, 1);
}

void	sr_min(t_stack *data)
{
	int	i;
	int	min;

	i = 0;
	min = data->stack_a[0];
	while (i < data->size_a)
	{
		if (min > data->stack_a[i])
			min = data->stack_a[i];
		i++;
	}
	i = 0;
	while (i < data->size_a)
	{
		if (min == data->stack_a[i])
			break ;
		i++;
	}
	push_to_b(i, data);
}

void	sorting(t_stack *data)
{
	if (data->size_a == 1)
		exit (0);
	else if (data->size_a == 2)
	{
		sa(data, 1);
	}
	else if (data->size_a == 3)
		arr_3(data);
	else if (data->size_a <= 5)
	{
		if (data->size_a == 5)
			sr_min(data);
		sr_min(data);
		arr_3(data);
		if (data->size_a + data->size_b == 5)
			pa(data, 1);
		pa(data, 1);
	}
}
