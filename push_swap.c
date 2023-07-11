/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:12:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/11 23:05:12 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_ls **src, t_ls **dest)
{
	t_ls	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_ls **stack_a, t_ls **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_ls **stack_a, t_ls **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}


	// if (get_index(head_a, get_min_node(head_a)) == 0)
	// 	push_b(head_a, head_b);
	// else
	// {
	// 	while (get_index(head_a, get_min_node(head_a)) >= 2)
	// 		reverse_rotate_a(head_a);
	// 	push_b(head_a, head_b);
	// 	ac = ft_lstsize(head_a);
	// 	if (ac != 3)
	// 	{
	// 		while (get_index(head_a, get_min_node(head_a)) < 2)
	// 			rotate_a(head_a);
	// 		push_b(head_a, head_b);
	// 	}
	// }
	// sort_thre_nbr(head_a);
	// push_a(head_a, head_b);