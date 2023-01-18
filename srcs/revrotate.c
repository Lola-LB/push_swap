/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:07:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 13:26:38 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack **a, char c)
{
	t_stack	*first;
	t_stack	*bflast;

	first = *a;
	if (first && first->next)
	{
		bflast = get_nth(a, get_len(a) - 2);
		*a = bflast->next;
		(*a)->next = first;
		bflast->next = NULL;
	}
	if (c)
		ft_printf("rr%c\n", c);
}

void	revrotate_both(t_stack **a, t_stack **b, char c)
{
	revrotate(a, 0);
	revrotate(b, 0);
	if (c)
		ft_printf("rrr\n");
}
