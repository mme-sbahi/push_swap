/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:11:06 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 15:14:45 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *data, int n)
{
	int	*tmp_stack;
	int	tmp;
	int	i;

	if (data->size_a != 0)
	{
		tmp = data->stack_a[0];
		tmp_stack = (int *)malloc(sizeof(int) * --data->size_a);
		i = -1;
		while (++i < data->size_a)
			tmp_stack[i] = data->stack_a[i + 1];
		free(data->stack_a);
		data->stack_a = tmp_stack;
		tmp_stack = (int *)malloc(sizeof(int) * ++data->size_b);
		i = 0;
		tmp_stack[0] = tmp;
		while (++i < data->size_b)
			tmp_stack[i] = data->stack_b[i - 1];
		free (data->stack_b);
		data->stack_b = tmp_stack;
		if (n)
			write(1, "pb\n", 3);
	}
}

void	pa(t_stack *data, int n)
{
	int	*tmp_stack;
	int	tmp;
	int	i;

	if (data->size_b != 0)
	{
		tmp = data->stack_b[0];
		tmp_stack = (int *)malloc(sizeof(int) * --data->size_b);
		i = -1;
		while (++i < data->size_b)
			tmp_stack[i] = data->stack_b[i + 1];
		free(data->stack_b);
		data->stack_b = tmp_stack;
		tmp_stack = (int *)malloc(sizeof(int) * ++data->size_a);
		i = 0;
		tmp_stack[0] = tmp;
		while (++i < data->size_a)
			tmp_stack[i] = data->stack_a[i - 1];
		free(data->stack_a);
		data->stack_a = tmp_stack;
		if (n)
			write(1, "pa\n", 3);
	}
}
