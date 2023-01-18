/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:55:51 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:39:34 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_alldigit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit((int) *s))
			return (0);
		++s;
	}
	return (1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	check_int(char *str)
{
	if (ft_strcmp(str, "-2147483648") == 0)
		return (1);
	if (*str == '-')
		++str;
	if (ft_strlen(str) > 10 || !ft_alldigit(str)
		|| (ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0))
		return (0);
	return (1);
}

int	check_args(int len, char **list)
{
	int	i;

	while (len > 1)
	{
		if (!check_int(*(list + len - 1)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(*(list + len - 1), *(list + i)) == 0)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			++i;
		}
		len--;
	}
	return (1);
}
