/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:07:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 13:26:18 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a, char c)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	if (first)
	{
		last = get_nth(a, get_len(a) - 1);
		*a = first->next;
		last->next = first;
		first->next = NULL;
	}
	if (c)
		ft_printf("r%c\n", c);
}

void	rotate_both(t_stack **a, t_stack **b, char c)
{
	rotate(a, 0);
	rotate(b, 0);
	if (c)
		ft_printf("rr\n");
}

void	rotate_to(t_stack **a, int n, char c)
{
	int		len;

	len = get_len(a);
	if (n <= len / 2)
	{
		while (n--)
			rotate(a, c);
	}
	else
	{
		while (len - n++)
			revrotate(a, c);
	}
}

void	rotate_both_to(t_stack **a, t_stack **b, int i, int j)
{
	int		len_a;
	int		len_b;

	len_a = get_len(a);
	len_b = get_len(b);
	if (i <= len_a / 2 && j <= len_b / 2)
	{
		while (i && j)
		{
			rotate_both(a, b, 1);
			--i;
			--j;
		}
	}
	else if (i > len_a / 2 && j > len_b / 2)
	{
		while (len_a - i && len_b - j)
		{
			revrotate_both(a, b, 1);
			++i;
			++j;
		}
	}
	rotate_to(b, j, 'b');
	rotate_to(a, i, 'a');
}
