/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:55:33 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/14 13:34:19 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libfth/libft.h"

int	ft_argument_check(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] >= 9 && av[j][i] <= 13) || av[j][i] == ' ')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_sign(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = ft_number(str, i);
	return (num);
}

char	*ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (&str[i]);
}

int	ft_control_int(long num)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (!(num <= max && num >= min))
		return (1);
	return (0);
}

int	ft_num_check(char **av)
{
	int		i;
	int		result;

	av = ft_split(av[1], ' ');
	result = ft_ps_atoi(av[0], &i);
	ft_free_str(av);
	return (result);
}
