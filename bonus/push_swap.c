/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:12:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 01:37:52 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_a(t_ls **head)
{
	int				tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = (*head)->next->contnt;
	(*head)->next->contnt = (*head)->contnt;
	(*head)->contnt = tmp;
}

t_ls	*reverse_rotate_a(t_ls **head)
{
	t_ls			*last;
	t_ls			*ptr1;
	t_ls			*tmp;

	ptr1 = (*head);
	last = ft_lstlast((*head));
	while (ptr1 && ptr1->next && ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	tmp = (*head);
	(*head) = last;
	(*head)->next = tmp;
	ptr1->next = NULL;
	return ((*head));
}

t_ls	*reverse_rotate_b(t_ls **head)
{
	t_ls			*last;
	t_ls			*ptr1;
	t_ls			*tmp;

	ptr1 = (*head);
	last = ft_lstlast((*head));
	while (ptr1 && ptr1->next && ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	tmp = (*head);
	(*head) = last;
	(*head)->next = tmp;
	ptr1->next = NULL;
	return ((*head));
}

void	push_a(t_ls **head_a, t_ls **head_b)
{
	t_ls			*tmp;

	if (!(*head_b))
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
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
}
