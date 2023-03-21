/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:40 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:23 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stack
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int pos;
	int check;
}t_stack;


char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup( const char *source);
char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(char *first, char *second);
long	ft_atoi(const char *str);
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
int	sorted(t_stack	*data);
void    arr_3(t_stack *data);
void    sorting(t_stack *data);
void    indexing(t_stack *data);
void    push_to_b(int pos, t_stack *data);
void	sort_100(t_stack *data);
void	f_stackb(t_stack *data);
void	ft_search(t_stack *data, int max);
void	indexing(t_stack *data);
void	sort_over_100(t_stack *data);
void	search_small_ae(t_stack *data);
void	f_stackbe(t_stack *data);
void	ft_searche(t_stack *data);
void	indexinge(t_stack *data);



#endif