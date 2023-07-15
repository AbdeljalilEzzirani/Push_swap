/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:56:43 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 14:13:30 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	get_index_min_to_max(t_ls **head)
{
	int				i;
	t_ls			*min;
	t_ls			*current;

	min = (*head);
	while (min)
	{
		i = 1;
		current = (*head);
		while (current)
		{
			if (min->contnt > current->contnt)
				i++;
			current = current->next;
		}
		min->index = i;
		min = min->next;
	}
}

void	get_index_for_list(t_ls **head_a)
{
	int				i;
	t_ls			*tmp;

	i = 1;
	tmp = (*head_a);
	while (tmp)
	{
		tmp->count = i;
		i++;
		tmp = tmp->next;
	}
}

void	check_pos_three_nbr_push(t_ls **head_a, t_ls **head_b, int count)
{
	if (count == 1)
		push_b(head_a, head_b);
	else if (count == 2)
	{
		rotate_a(head_a);
		push_b(head_a, head_b);
	}
	else if (count == 3)
	{
		rotate_a(head_a);
		rotate_a(head_a);
		push_b(head_a, head_b);
	}
	else if (count == 4)
	{
		reverse_rotate_a(head_a);
		push_b(head_a, head_b);
	}
}

void	check_pos_five_nbr_push(t_ls **head_a, t_ls **head_b, int count)
{
	if (count == 1)
		push_b(head_a, head_b);
	else if (count == 2)
	{
		rotate_a(head_a);
		push_b(head_a, head_b);
	}
	else if (count == 3)
	{
		rotate_a(head_a);
		rotate_a(head_a);
		push_b(head_a, head_b);
	}
	else if (count == 4)
	{
		reverse_rotate_a(head_a);
		reverse_rotate_a(head_a);
		push_b(head_a, head_b);
	}
	else if (count == 5)
	{
		reverse_rotate_a(head_a);
		push_b(head_a, head_b);
	}
}
