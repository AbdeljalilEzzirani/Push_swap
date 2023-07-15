/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:29:42 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 14:12:42 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_a_rotate_b(t_ls **head_a, t_ls **head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
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
}

void	rotate_b(t_ls **head_b)
{
	t_ls			*tmp;
	t_ls			*new_head_b;

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
