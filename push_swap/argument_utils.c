/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:40:41 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 12:12:19 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libfth/libft.h"

int	ft_word_counter(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_jumper(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_number(char *str, int i)
{
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_ps_atoi(char *str, int *n)
{
	unsigned int		i;
	int					sign;
	unsigned long int	num;

	num = 0;
	sign = 1;
	i = ft_jumper(str, &sign);
	if (ft_number(str, i) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (ft_control_int(num * sign))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (ft_control_int(num * sign))
		return (-1);
	*n = num * sign;
	return (1);
}
