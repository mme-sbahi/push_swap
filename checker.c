/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:54 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:12:53 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str(char *str, t_stack *data)
{
	if (ft_strnstr(str, "sa\n", 3))
		sa(data, 0);
	else if (ft_strnstr(str, "sb\n", 3))
		sb(data, 0);
	else if (ft_strnstr(str, "ss\n", 3))
		ss(data, 0);
	else if (ft_strnstr(str, "pa\n", 3))
		pa(data, 0);
	else if (ft_strnstr(str, "pb\n", 3))
		pb(data, 0);
	else if (ft_strnstr(str, "ra\n", 3))
		ra(data, 0);
	else if (ft_strnstr(str, "rb\n", 3))
		rb(data, 0);
	else if (ft_strnstr(str, "rr\n", 3))
		rr(data, 0);
	else if (ft_strnstr(str, "rra\n", 4))
		rra(data, 0);
	else if (ft_strnstr(str, "rrb\n", 4))
		rrb(data, 0);
	else if (ft_strnstr(str, "rrr\n", 4))
		rrr(data, 0);
	else
		ft_error("Error\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	data;

	if (argc <= 2)
		ft_error("Error");
	parsing(argv, &data);
	str = ft_strdup("");
	str = get_next_line(0);
	while (str)
	{
		check_str(str, &data);
		free (str);
		str = get_next_line(0);
	}
	if (sorted_check(&data) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
