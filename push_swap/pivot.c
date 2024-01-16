/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:39:48 by albozkur          #+#    #+#             */
/*   Updated: 2023/12/27 18:07:18 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_partition(int *array, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_quicksort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(array, low, high);
		ft_quicksort(array, low, pi - 1);
		ft_quicksort(array, pi + 1, high);
	}
}

int	ft_get_middle(int *array, int size)
{
	int	pivot;
	int	*tmp;
	int	i;

	pivot = 0;
	i = 0;
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	while (i < size)
	{
		tmp[i] = array[i];
		i++;
	}
	ft_quicksort(tmp, 0, size - 1);
	pivot = tmp[size / 2];
	free(tmp);
	return (pivot);
}
