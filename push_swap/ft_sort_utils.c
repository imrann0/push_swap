/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:41:11 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:08 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascending(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_descending(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_repeat(t_stack *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, int status)
{
	if (status == 0)
		pb(stack, 0);
	else
		pa(stack, 0);
	len--;
	return (len);
}

void	ft_sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, 0);
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		rra(s, 0);
	}
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 0);
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		ra(s, 0);
	}
	else if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 0);
}
