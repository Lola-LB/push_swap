/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:43:27 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:46:11 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error()
{
	write(1, "Error\n", 6);
	return(0);
}

int	*sorted_list(int argc, char **argv)
{
	int	*list;
	int	i;
	
	list = malloc(sizeof(int) * (argc - 1));
	if (!list)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		*(list + i) = ft_atoi(*(argv + i + 1));
		++i;
	}
	list = quick_sort(list, argc - 1);
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	int		*list;

	if (argc > 1 && check_args(argc, argv))
	{
		list = sorted_list(argc, argv);
		if (!list)
			return(error());
		a = init_stack(argc - 1, argv + 1);
		b = init_stack(0, NULL);
		if (!b || !a)
		{
			free(list);
			free_stack(a);
			free_stack(b);
			return(error());
		}
		push_swap(list, argc - 1, a, b);
	}
	return (0);
}
