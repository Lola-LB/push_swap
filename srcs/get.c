/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:06:55 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:42:29 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max(t_stack **a)
{
	t_stack	*max;
	t_stack	*elem;

	max = *a;
	elem = (*a)->next;
	while (elem)
	{
		if (elem->i > max->i)
			max = elem;
		elem = elem->next;
	}
	return (max);
}

t_stack	*get_min(t_stack **a)
{
	t_stack	*min;
	t_stack	*elem;

	min = *a;
	elem = (*a)->next;
	while (elem)
	{
		if (elem->i <= min->i)
			min = elem;
		elem = elem->next;
	}
	return (min);
}

t_stack	*get_nth(t_stack **a, int n)
{
	t_stack	*elem;

	if (!a)
		return (NULL);
	elem = *a;
	while (elem && elem->next && n--)
		elem = elem->next;
	return (elem);
}

int	get_loc(t_stack **a, t_stack *to_find)
{
	t_stack	*elem;
	int		loc;

	loc = 0;
	elem = *a;
	while (elem != to_find && elem)
	{
		elem = elem->next;
		++loc;
	}
	return (loc);
}

int	get_len(t_stack **a)
{
	t_stack	*elem;
	int		len;

	len = 0;
	elem = *a;
	while (elem)
	{
		elem = elem->next;
		++len;
	}
	return (len);
}
