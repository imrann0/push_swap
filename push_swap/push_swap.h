/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:13:43 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 14:11:27 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}		t_stack;

void	ft_sort(t_stack *stack, int size);

int		ft_argument_check(char **av);
int		ft_control_int(long num);
int		ft_check_sign(char *str);
char	*ft_isspace(char *str);
int		ft_num_check(char **av);

int		ft_mini_sort(t_stack *stack);
int		ft_mini_sort_three(t_stack *s, int len);
int		ft_mini_sort_b(t_stack *s, int len);

int		ft_dualstack_sort(t_stack *stack, int len);
int		ft_dualstack_sort_a(t_stack *stack, int len, int count);
int		ft_dualstack_sort_b(t_stack *stack, int len, int count);

int		is_sorted_ascending(int *array, int size);
int		is_sorted_descending(int *array, int size);
int		ft_check_repeat(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int status);
void	ft_sort_three(t_stack *s);

void	ft_free(char **av, t_stack *stack, int status);
void	ft_error(t_stack *stack, int status);
void	ft_free_str(char **av);

int		ft_word_counter(char **av);
int		ft_ps_atoi(char *str, int *n);
int		ft_word_counter(char **av);
int		ft_number(char *str, int i);
int		ft_jumper(char *str, int *sign);

void	ft_swap(int *a, int *b);
int		ft_partition(int *array, int low, int high);
void	ft_quicksort(int *array, int low, int high);
int		ft_get_middle(int *stack_a, int size);

void	pa(t_stack *stack, int print);
void	sa(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rra(t_stack *stack, int print);

void	pb(t_stack *stack, int print);
void	sb(t_stack	*stack, int print);
void	rb(t_stack	*stack, int print);
void	rrb(t_stack *stack, int print);

void	ss(t_stack	*stack, int print);
void	rr(t_stack	*stack, int print);
void	rrr(t_stack *stack, int print);

#endif
