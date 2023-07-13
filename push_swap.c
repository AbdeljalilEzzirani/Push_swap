/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:12:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/13 21:21:23 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_ls **head)
{
	int			tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = (*head)->next->contnt;
	(*head)->next->contnt = (*head)->contnt;
	(*head)->contnt = tmp;
	write(1, "sa\n", 3);
}

t_ls	*reverse_rotate_a(t_ls **head)
{
	t_ls		*last;
	t_ls		*ptr1;
	t_ls		*tmp;

	ptr1 = (*head);
	last = ft_lstlast((*head));
	while (ptr1 && ptr1->next && ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	tmp = (*head);
	(*head) = last;
	(*head)->next = tmp;
	ptr1->next = NULL;
	write(1, "rra\n", 4);
	return ((*head));
}

t_ls	*reverse_rotate_b(t_ls **head)
{
	t_ls		*last;
	t_ls		*ptr1;
	t_ls		*tmp;

	ptr1 = (*head);
	last = ft_lstlast((*head));
	while (ptr1 && ptr1->next && ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	tmp = (*head);
	(*head) = last;
	(*head)->next = tmp;
	ptr1->next = NULL;
	write(1, "rrb\n", 4);
	return ((*head));
}

void	push_a(t_ls **head_a, t_ls **head_b)
{
	t_ls				*tmp;

	if (!(*head_b))
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_ls **head_a, t_ls **head_b)
{
	t_ls			*tmp;

	if (!(*head_a))
		return ;
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	write(1, "pb\n", 3);
}

void	rotate_a_rotate_b(t_ls **head_a, t_ls **head_b)
{
	rotate_a(head_a);
	rotate_a(head_b);
	write(1, "rr\n", 3);
}

void	rotate_a(t_ls **head_a)
{
	t_ls		*tmp;
	t_ls		*new_head_a;

	if (!(*head_a) || !(*head_a)->next)
		return ;
	new_head_a = (*head_a)->next;
	tmp = (*head_a);
	while ((*head_a))
	{
		if ((*head_a)->next == NULL)
		{
			(*head_a)->next = tmp;
			tmp->next = NULL;
		}
		(*head_a) = (*head_a)->next;
	}
	(*head_a) = new_head_a;
	write(1, "ra\n", 3);
}

void	rotate_b(t_ls **head_b)
{
	t_ls		*tmp;
	t_ls		*new_head_b;

	if (!(*head_b) || !(*head_b)->next)
		return ;
	new_head_b = (*head_b)->next;
	tmp = (*head_b);
	while ((*head_b))
	{
		if ((*head_b)->next == NULL)
		{
			(*head_b)->next = tmp;
			tmp->next = NULL;
		}
		(*head_b) = (*head_b)->next;
	}
	(*head_b) = new_head_b;
	write(1, "rb\n", 3);
}
