/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:21:11 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/21 18:17:08 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *data, int n)
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

void    sb(t_stack *data, int n)
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

void	pb(t_stack *data, int n)
{
	int *tmp_stack;
	int tmp;
	int i;
	
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
		i = 1;
		tmp_stack[0] = tmp;
		while (i < data->size_b)
		{
			tmp_stack[i] = data->stack_b[i - 1];
			i++;
		}
		free(data->stack_b);
		data->stack_b = tmp_stack;
		if (n)
			write(1, "pb\n", 3);
	}
}

void	pa(t_stack *data, int n)
{
	int *tmp_stack;
	int tmp;
	int i;
	
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
		i = 1;
		tmp_stack[0] = tmp;
		while (i < data->size_a)
		{
			tmp_stack[i] = data->stack_a[i - 1];
			i++;
		}
		free(data->stack_a);
		data->stack_a = tmp_stack;
		if (n)
			write(1, "pa\n", 3);
	}
}

void	ra(t_stack *data, int n)
{
	int tmp;
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

void	rb(t_stack *data, int n)
{
	int tmp;
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

void rra(t_stack *data, int n)
{
	int tmp;
	int i;
	
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

void rrb(t_stack *data, int n)
{
	int tmp;
	int i;
	
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

void rrr(t_stack *data, int n)
{
	rra(data, 0);
	rrb(data, 0);
	if (n)
		write(1, "rrr\n", 4);
}
