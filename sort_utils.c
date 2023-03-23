/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:52:11 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 14:44:18 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *data)
{
	int	i;
	int	j;
	int	cnt;
	int	*tmp;

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
