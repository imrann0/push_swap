/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:20:32 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 14:01:08 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include "Libfth/libft.h"

static int	process_command(t_stack *stack, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return (sa(stack, 1), 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		return (ra(stack, 1), 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		return (pa(stack, 1), 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		return (sb(stack, 1), 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		return (rb(stack, 1), 1);
	else if (!ft_strncmp(str, "pb\n", 3))
		return (pb(stack, 1), 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		return (ss(stack, 1), 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		return (rr(stack, 1), 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		return (rra(stack, 1), 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		return (rrb(stack, 1), 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		return (rrr(stack, 1), 1);
	else
		return (0);
}

static void	ft_checker(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strlen(str) != 3 && ft_strlen(str) != 4)
			return (ft_putstr_fd("Error\n", 2), exit(0));
		if (process_command(stack, str) == 0)
			return (ft_putstr_fd("Error\n", 2), exit(0));
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted_ascending(stack->a, stack->size_a - 1) && stack->size_b == 0)
		return (ft_putstr_fd("OK\n", 1));
	else
		return (ft_putstr_fd("KO\n", 2));
}

static void	ft_swap_checker(char **av, int status)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	size = ft_word_counter(av);
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return (exit(0));
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
	ft_checker(stack);
	ft_free(av, stack, 0);
}

int	main(int ar, char **av)
{
	int		i;

	i = 0;
	if (ar == 1)
		return (0);
	else if (ar == 2 && ft_num_check(av) == -1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (av[1][0] == '\0' || !ft_strlen(ft_isspace(av[1])))
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
		ft_swap_checker(av, 2);
		ft_free_str(av);
	}
	else
		ft_swap_checker(++av, 1);
}
