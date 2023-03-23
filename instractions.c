/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:21:11 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 13:29:37 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *data, int n)
{
	int	tmp;

	if (data->size_a > 1)
	{
		tmp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = tmp;
		if (n == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *data, int n)
{
	int	tmp;

	if (data->size_b > 1)
	{
		tmp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = tmp;
		if (n == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *data, int n)
{
	sa(data, 0);
	sb(data, 0);
	if (n)
		write(1, "ss\n", 3);
}

void	ra(t_stack *data, int n)
{
	int	tmp;
	int	i;

	if (data->size_a > 1)
	{
		tmp = data->stack_a[0];
		i = 0;
		while (i < data->size_a)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i - 1] = tmp;
		if (n)
			write(1, "ra\n", 3);
	}
}
