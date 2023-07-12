/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/12 17:15:14 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ls	*sort_thre_nbr(t_ls **h)
{
	if ((*h)->content > (*h)->next->content && (*h)->next->content
		< (*h)->next->next->content && (*h)->next->next->content > (*h)->content)
		swap_a(h);
	else if ((*h)->content > (*h)->next->content && (*h)->next->content
		> (*h)->next->next->content && (*h)->next->next->content < (*h)->content)
	{	
		swap_a(h);
		(*h) = reverse_rotate_a(h);
	}
	else if ((*h)->content > (*h)->next->content && (*h)->next->content
		< (*h)->next->next->content && (*h)->next->next->content < (*h)->content)
		rotate_a(h);
	else if ((*h)->content < (*h)->next->content && (*h)->next->content
		> (*h)->next->next->content && (*h)->next->next->content > (*h)->content)
	{
		swap_a(h);
		rotate_a(h);
	}
	else if ((*h)->content < (*h)->next->content && (*h)->next->content
		> (*h)->next->next->content && (*h)->next->next->content < (*h)->content)
		(*h) = reverse_rotate_a(h);
	return (*h);
}

// t_ls	*get_min_node(t_ls *head)
// {
// 	t_ls			*min;

// 	min = head;
// 	while (head)
// 	{
// 		if (min->content > head->content)
// 			min = head;
// 		head = head->next;
// 	}
// 	return (min);
// }

void	sort_four_nbr(t_ls **head_a, t_ls **head_b, int ac)
{
	t_ls			*ptr;

	(void)ac;
	get_index_min_to_max(head_a);
	get_index_for_list(head_a);
	ptr = (*head_a);
	while (ptr)
	{
		if (ptr->index == 1)
		{
			check_pos_three_nbr_push(head_a, head_b, ptr->count);
			sort_thre_nbr(head_a);
			push_a(head_a, head_b);
			return ;
		}
		ptr = ptr->next;
	}
}

void	sort_five_nbr(t_ls **head_a, t_ls **head_b, int ac)
{
	t_ls			*ptr;

	(void)ac;
	get_index_min_to_max(head_a);
	get_index_for_list(head_a);
	ptr = (*head_a);
	while (ptr)
	{
		if (ptr->index == 1)
		{
			check_pos_five_nbr_push(head_a, head_b, ptr->count);
			sort_four_nbr(head_a, head_b, ac);
			push_a(head_a, head_b);
			return ;
		}
		ptr = ptr->next;
	}
}

t_ls	*algo_sort(t_ls **head_a, t_ls **head_b, int ac)
{
	if (ac == 2)
		swap_a(head_a);
	else if (ac == 3)
		(*head_a) = sort_thre_nbr(head_a);
	else if (ac == 4)
		sort_four_nbr(head_a, head_b, ac);
	else if (ac == 5)
		sort_five_nbr(head_a, head_b, ac);
	return ((*head_a));
}

int	main(int ac, char **av)
{
	t_ls		*head_a;
	t_ls		*head_b;

	if (ac == 1)
		return (0);
	head_a = check_parsing(av);
	get_index_min_to_max(&head_a);
	ac = ft_lstsize(head_a);
	head_b = NULL;
	head_a = algo_sort(&head_a, &head_b, ac);
	// while (head_a)
	// {
	// 	printf("head_a node --> %d\n", head_a->content);
	// 	head_a = head_a->next;
	// }
	// printf ("\n\n\n\n");
	// while (head_b)
	// {
	// 	printf("head_b node --> %d\n", head_b->content);
	// 	head_b = head_b->next;
	// }
}
