/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:12:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 14:12:53 by abez-zir         ###   ########.fr       */
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

void	swap_a_swap_b(t_ls **stack_a, t_ls **stack_b)
{
	swap_a(stack_a);
	swap_a(stack_b);
}

t_ls	*reverse_rotate_a(t_ls **head)
{
	t_ls			*last;
	t_ls			*ptr1;
	t_ls			*tmp;

	if (!(*head))
		return (NULL);
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

	if (!(*head))
		return (NULL);
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

void	rrr(t_ls **stack_a, t_ls **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
