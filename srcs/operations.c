/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:29:33 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:40:18 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **a)
{
	t_stack	*min;
	t_stack	*elem;
	t_stack	*next;

	min = get_min(a);
	elem = min;
	next = get_next(a, elem);
	while (next != min)
	{
		if (next->i < elem->i)
			return (0);
		elem = next;
		next = get_next(a, elem);
	}
	return (1);
}

int	exist_sup(t_stack **a, int med)
{
	t_stack	*elem;

	elem = *a;
	while (elem)
	{
		if (elem->i > med)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void	empty_a(int *list, int len, t_stack **a, t_stack **b)
{
	int	med;

	med = *(list + len / 2);
	while (get_len(a) > 3 && !sorted(a))
	{
		while (exist_sup(a, med) && !sorted(a))
		{
			if ((*a)->i > med)
				push(a, b, 'b');
			else
				rotate(a, 'a');
		}
		len /= 2;
		med = *(list + len / 2);
	}
	if (!sorted(a))
		swap(a, 'a');
}

void	insert_sort(t_stack **a, t_stack **b)
{
	t_stack	*to_insert;

	while (*b)
	{
		to_insert = min_elem(a, b);
		rotate_both_to(a, b, loc_toinsert(a, to_insert), get_loc(b, to_insert));
		push(b, a, 'a');
	}
}

void	push_swap(int *list, int len, t_stack **a, t_stack **b)
{
	empty_a(list, len, a, b);
	insert_sort(a, b);
	rotate_to(a, get_loc(a, get_min(a)), 'a');
}
