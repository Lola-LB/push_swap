/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:59:15 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:06:47 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = tmp;
	}
	if (c)
		ft_printf("p%c\n", c);
}

void	swap(t_stack **a, char c)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (c)
		ft_printf("s%c\n", c);
}

void	swap_both(t_stack **a, t_stack **b, char c)
{
	swap(a, 0);
	swap(b, 0);
	if (c)
		ft_printf("s%c\n", c);
}
