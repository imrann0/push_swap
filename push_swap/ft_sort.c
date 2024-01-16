/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:41:19 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 12:51:18 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack, int size)
{
	if (is_sorted_ascending(stack->a, stack->size_a - 1))
		return ;
	else if (size == 2)
		sa(stack, 0);
	else if (size == 3)
		ft_sort_three(stack);
	else
		ft_dualstack_sort(stack, size);
}
