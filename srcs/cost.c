/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:17:52 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 13:50:10 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loc_toinsert(t_stack **a, t_stack *to_insert)
{
	int		len;
	int		loc;
	t_stack	*elem;

	loc = 0;
	len = get_len(a);
	if (get_max(a)->i <= to_insert->i || get_min(a)->i >= to_insert->i)
		loc = get_loc(a, get_min(a));
	else if (!(((*a)->i >= to_insert->i
				&& get_nth(a, len - 1)->i <= to_insert->i)))
	{
		elem = *a;
		loc = 1;
		while (!(elem->i <= to_insert->i
				&& elem->next->i >= to_insert->i) && elem->next)
		{
			elem = elem->next;
			++loc;
		}
	}
	return (loc);
}

int	cost(t_stack **a, t_stack *to_insert)
{
	int	cost;

	cost = loc_toinsert(a, to_insert);
	cost = ft_min(cost, get_len(a) - cost);
	return (cost);
}

t_stack	*min_elem(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	t_stack	*min_elem;
	int		min_cost;
	int		n;
	int		len;

	len = get_len(b);
	min_elem = *b;
	min_cost = cost(a, min_elem);
	elem = min_elem->next;
	n = 1;
	while (elem)
	{
		if (cost(a, elem) + ft_min(n, len - n) < min_cost)
		{
			min_cost = cost(a, elem) + ft_min(n, len - n);
			min_elem = elem;
		}
		elem = elem->next;
		++n;
	}
	return (min_elem);
}
