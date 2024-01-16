/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:40:09 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 14:12:13 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dualstack_sort(t_stack *stack, int len)
{
	int	pivot;
	int	pivot_b;
	int	i;

	i = len;
	pivot = ft_get_middle(stack->a, len);
	while (len != i / 2 + i % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, 0);
		else
		{
			pivot_b = ft_get_middle(stack->b, stack->size_b);
			if ((stack->b[0] <= pivot_b) && (stack->size_b > 2))
				rr(stack, 0);
			else
				ra(stack, 0);
		}
	}
	ft_dualstack_sort_a(stack, i / 2 + i % 2, 0);
	ft_dualstack_sort_b(stack, i / 2, 0);
	return (1);
}

int	ft_dualstack_sort_a(t_stack *stack, int len, int count)
{
	int	pivot;
	int	i;

	if (is_sorted_ascending(stack->a, stack->size_a - 1))
		return (1);
	if (len == 2)
		return (ft_mini_sort(stack));
	else if (len == 3 && stack->size_a == 3)
		return (ft_sort_three(stack), 0);
	else if (len == 3)
		return (ft_mini_sort_three(stack, len));
	pivot = ft_get_middle(stack->a, len);
	i = len;
	while (len != i / 2 + i % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, 0);
		else if (++count)
			ra(stack, 0);
	}
	while (i / 2 + i % 2 != stack->size_a && count--)
		rra(stack, 0);
	ft_dualstack_sort_a(stack, i / 2 + i % 2, 0);
	ft_dualstack_sort_b(stack, i / 2, 0);
	return (1);
}

int	ft_dualstack_sort_b(t_stack *stack, int len, int count)
{
	int	pivot;
	int	i;

	if (!count && is_sorted_descending(stack->b, stack->size_b - 1))
		while (len--)
			pa(stack, 0);
	if (len <= 3)
		return (ft_mini_sort_b(stack, len));
	pivot = ft_get_middle(stack->b, len);
	i = len;
	while (len != i / 2)
	{
		if (stack->b[0] >= pivot && (len--))
			pa(stack, 0);
		else if (++count)
			rb(stack, 0);
	}
	while (i / 2 != stack->size_b && count--)
		rrb(stack, 0);
	ft_dualstack_sort_a(stack, i / 2 + i % 2, 0);
	ft_dualstack_sort_b(stack, i / 2, 0);
	return (1);
}
