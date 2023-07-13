/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:56:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/13 22:44:46 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assoocie(t_ls *head_a, int chunk)
{
	while (head_a)
	{
		if (head_a->index < chunk)
			return (1);
		head_a = head_a->next;
	}
	return (0);
}

void	sort_one_hundred(t_ls **head_a, t_ls **head_b, int ac)
{
	int				chunck;
	int				moyenne;

	chunck = ac / 5;
	moyenne = chunck / 2;
	get_index_min_to_max(head_a);
	get_index_for_list(head_a);
	chunk_job(head_a, head_b, chunck, moyenne);
	chunk_push_a(head_a, head_b);
}

int	get_pos(t_ls *head_b, int index)
{
	int	i;

	i = 0;
	while (head_b)
	{
		if (head_b->index == index)
			return (i);
		i++;
		head_b = head_b->next;
	}
	return (0);
}

void	chunk_push_a(t_ls **head_a, t_ls **head_b)
{
	int			size_list;

	size_list = ft_lstsize(*head_b);
	while (*head_b)
	{
		if ((*head_b)->index == size_list)
		{
			push_a(head_a, head_b);
			size_list--;
		}
		if (get_pos(*head_b, size_list) < size_list / 2)
		{
			while (*head_b && get_pos(*head_b, size_list) != 0)
				rotate_b(head_b);
		}
		else
		{
			while (*head_b && get_pos(*head_b, size_list) != 0)
				reverse_rotate_b(head_b);
		}
	}
}

void	chunk_job(t_ls **head_a, t_ls **head_b, int chunck, int moyenne)
{
	int			fix;

	fix = chunck;
	while ((*head_a))
	{
		while ((*head_a) && assoocie(*head_a, chunck))
		{
			if ((*head_a)->index < chunck)
			{
				if ((*head_a)->index < moyenne)
				{
					push_b(head_a, head_b);
					rotate_b(head_b);
				}
				else
					push_b(head_a, head_b);
			}
			else
				rotate_a(head_a);
		}
		chunck += fix;
		moyenne += fix;
	}
}

void	get_max_max_nbr(t_ls **head_b)
{
	t_ls		*max;
	t_ls		*current;
	int			i;

	max = (*head_b);
	while (max)
	{
		i = 1;
		current = (*head_b);
		while (current)
		{
			if (max->contnt < current->contnt)
				i++;
			current = current->next;
		}
		max->index = i;
		max = max->next;
	}
}


	// get_max_max_nbr(&head_a);
