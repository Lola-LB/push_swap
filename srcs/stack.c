/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:04:38 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:44:44 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **s)
{
	t_stack	*elem;

	elem = *s;
	ft_printf("\nStack :\n");
	while (elem)
	{
		ft_printf("%i\n", elem->i);
		elem = elem->next;
	}
	ft_printf("\n");
}

t_stack	*init_elem(int i, t_stack *next)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->i = i;
	elem->next = next;
	return (elem);
}

t_stack	**init_stack(int len, char **list)
{
	t_stack	**s;
	t_stack	*elem;

	s = malloc(sizeof(t_stack *));
	if (!s)
		return (NULL);
	elem = NULL;
	*s = elem;
	while (len)
	{
		*s = init_elem(ft_atoi(*(list + len - 1)), elem);
		elem = *s;
		--len;
	}
	return (s);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	while (s && *s)
	{
		tmp = *s;
		*s = tmp->next;
		free(tmp);
	}
	if (s)
		free(s);
}

t_stack	*get_next(t_stack **a, t_stack *elem)
{
	if (elem->next)
		return (elem->next);
	return (*a);
}
