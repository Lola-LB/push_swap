/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:53:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 13:29:15 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap_left(int *pivot, int *n)
{
	int	temp;
	int	i;

	if (n > pivot)
	{
		temp = *pivot;
		*pivot = *n;
		i = 0;
		while (i < n - pivot - 1)
		{
			*(n - i) = *(n - i - 1);
			++i;
		}
		*(pivot + 1) = temp;
		return (pivot + 1);
	}
	return (pivot);
}

int	*swap_right(int *pivot, int *n)
{
	int	temp;
	int	i;

	if (n < pivot)
	{
		temp = *n;
		i = 0;
		while (i < pivot - n)
		{
			*(n + i) = *(n + i + 1);
			++i;
		}
		*pivot = temp;
		return (pivot - 1);
	}
	return (pivot);
}

int	quick_sorted(int *list, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (*(list + i) > *(list + i + 1))
			return (0);
		++i;
	}
	return (1);
}

int	*quick_sort(int *list, int len)
{
	int	*pivot;
	int	i;

	if (!quick_sorted(list, len))
	{
		pivot = list + len / 2;
		i = 0;
		while (i < len)
		{
			if (*(list + i) < *pivot && list + i > pivot)
				pivot = swap_left(pivot, list + i);
			else if (*(list + i) > *pivot && list + i < pivot)
				pivot = swap_right(pivot, list + i);
			else
				++i;
		}
		quick_sort(list, pivot - list);
		quick_sort(pivot, list + len - pivot);
	}
	return (list);
}
