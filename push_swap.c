/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:45:47 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/22 23:32:45 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	data;
	int		i;

	i = 0;
	(void)argc;
	parsing(argv, &data);
	if (!sorted_check(&data))
		exit(0);
	if (data.size_a > 5)
		sort_100(&data);
	else
		sorting(&data);
}
