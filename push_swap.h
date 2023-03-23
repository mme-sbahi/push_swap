/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:40 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/23 17:29:38 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	pos;
	int	check;
}t_stack;

char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(char *first, char *second);
long	ft_atoi(const char *str);
void	parsing(char **av, t_stack *data);
int		check_instractions(t_stack *data, int max);
void	sa(t_stack *data, int n);
void	sb(t_stack *data, int n);
void	ss(t_stack *data, int n);
void	pb(t_stack *data, int n);
void	pa(t_stack *data, int n);
void	ra(t_stack *data, int n);
void	rb(t_stack *data, int n);
void	rr(t_stack *data, int n);
void	rra(t_stack *data, int n);
void	rrb(t_stack *data, int n);
void	rrr(t_stack *data, int n);
int		sorted_check(t_stack	*data);
void	arr_3(t_stack *data);
void	sorting(t_stack *data);
void	indexing(t_stack *data);
void	push_to_b(int pos, t_stack *data);
void	sort_100(t_stack *data);
void	f_stackb(t_stack *data, int num);
void	ft_search(t_stack *data, int max);
void	indexing(t_stack *data);
void	ft_error(char *str);
int		ft_position(t_stack *data, int val);
void	norm_arr_3(t_stack *data);
void	norm_f_stackb(t_stack *data);
char	*join_arg(char **s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	check_esp(char	*str);
int		check_nb(char **str, t_stack *data);
#endif