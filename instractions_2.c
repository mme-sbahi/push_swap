/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:10:52 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 13:32:06 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *data, int n)
{
	rra(data, 0);
	rrb(data, 0);
	if (n)
		write(1, "rrr\n", 4);
}

void	rrb(t_stack *data, int n)
{
	int	tmp;
	int	i;

	tmp = data->stack_b[data->size_b - 1];
	i = data->size_b;
	while (--i)
	{
		data->stack_b[i] = data->stack_b[i - 1];
	}
	data->stack_b[0] = tmp;
	if (n)
		write(1, "rrb\n", 4);
}

void	rra(t_stack *data, int n)
{
	int	tmp;
	int	i;

	tmp = data->stack_a[data->size_a - 1];
	i = data->size_a;
	while (--i)
	{
		data->stack_a[i] = data->stack_a[i - 1];
	}
	data->stack_a[0] = tmp;
	if (n)
		write(1, "rra\n", 4);
}

void	rr(t_stack *data, int n)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		ra(data, 0);
		rb(data, 0);
		if (n)
			write(1, "rr\n", 3);
	}
}

void	rb(t_stack *data, int n)
{
	int	tmp;
	int	i;

	if (data->size_b > 1)
	{
		tmp = data->stack_b[0];
		i = 0;
		while (i < data->size_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i - 1] = tmp;
		if (n)
			write(1, "rb\n", 3);
	}
}
