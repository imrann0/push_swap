/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:41:26 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 13:08:22 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libfth/libft.h"
#include "push_swap.h"

void	ft_push_swap(char **av, int status)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	size = ft_word_counter(av);
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return ;
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
		return (free(stack->a), exit(0));
	stack->size_b = 0;
	while (++i < size)
		if (ft_ps_atoi(av[i], &stack->a[i]) == -1)
			return (ft_free(av, stack, status), exit(0));
	if (ft_check_repeat(stack, size) == -1)
		return (ft_free(av, stack, status), exit(0));
	ft_sort(stack, size);
	ft_free(av, stack, 0);
}

int	main(int ar, char **av)
{
	if (ar == 1)
		return (0);
	else if (av[1][0] == '\0' || !ft_strlen(ft_isspace(av[1])))
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (ar == 2 && ft_num_check(av) == -1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (ft_argument_check(av) && ar > 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (ar == 2)
	{
		av = ft_split(av[1], ' ');
		if (ft_check_sign(av[0]) == 0)
			return (ft_putstr_fd("Error\n", 2), ft_free_str(av), 0);
		if (av[1] == 0)
			return (ft_free_str(av), 0);
		ft_push_swap(av, 2);
		ft_free_str(av);
	}
	else
		ft_push_swap(++av, 1);
}
