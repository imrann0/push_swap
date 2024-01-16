/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:40:56 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/14 13:28:53 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libfth/libft.h"

void	ft_free(char **av, t_stack *stack, int status)
{
	if (status == 2)
	{
		ft_free_str(av);
	}
	ft_error(stack, status);
}

void	ft_error(t_stack *stack, int status)
{
	free (stack->a);
	free (stack->b);
	free (stack);
	if (status > 0)
		ft_putstr_fd("Error\n", 2);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
