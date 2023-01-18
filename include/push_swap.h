/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:45 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/02 14:43:03 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

struct	s_stack
{
	int				i;
	struct s_stack	*next;
} typedef	t_stack;

// utils
int		ft_alldigit(char *s);
int		ft_min(int a, int b);
int		check_args(int len, char **list);

// stack
t_stack	*init_elem(int i, t_stack *next);
t_stack	**init_stack(int len, char **list);
t_stack	*get_next(t_stack **a, t_stack *elem);
void	free_stack(t_stack **s);
void	print_stack(t_stack **s);

// operations
int		sorted(t_stack **a);
void	empty_a(int *list, int len, t_stack **a, t_stack **b);
void	insert_sort(t_stack **a, t_stack **b);
void	push_swap(int *list, int len, t_stack **a, t_stack **b);

// get
t_stack	*get_min(t_stack **a);
t_stack	*get_max(t_stack **a);
t_stack	*get_nth(t_stack **a, int n);
int		get_loc(t_stack **a, t_stack *to_find);
int		get_len(t_stack **a);

// push swap
void	push(t_stack **a, t_stack **b, char c);
void	swap(t_stack **a, char c);
void	swap_both(t_stack **a, t_stack **b, char c);

// rotate
void	rotate(t_stack **a, char c);
void	rotate_both(t_stack **a, t_stack **b, char c);
void	rotate_to(t_stack **a, int n, char c);
void	rotate_both_to(t_stack **a, t_stack **b, int i, int j);

// revrotate
void	revrotate(t_stack **a, char c);
void	revrotate_both(t_stack **a, t_stack **b, char c);

// cost
t_stack	*min_elem(t_stack **a, t_stack **b);
int	cost(t_stack **a, t_stack *to_insert);
int	loc_toinsert(t_stack **a, t_stack *to_insert);

// quick sort
int	*quick_sort(int *list, int len);
int	quick_sorted(int *list, int len);

#endif
