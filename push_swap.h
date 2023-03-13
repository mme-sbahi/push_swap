/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:04:40 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/03/13 18:31:36 by mmesbahi         ###   ########.fr       */
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
}t_stack;


char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup( const char *source);
char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strncmp(char *first, char *second);
long	ft_atoi(const char *str);
void	sa(t_stack *data, int n);
void	sb(t_stack *data, int n);
void	ss(t_stack *data, int n);
void	pb(t_stack *data, int n);
void	pa(t_stack *data, int n);
void	ra(t_stack *data, int n);
void	rb(t_stack *data, int n);
void	rr(t_stack *data, int n);
void rra(t_stack *data, int n);
void rrb(t_stack *data, int n);

#endif