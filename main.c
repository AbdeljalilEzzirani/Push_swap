/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/12 00:16:20 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_ls *head)
{
	int			tmp;

	tmp = head->next->content;//
	head->next->content = head->content;//5
	head->content = tmp;
	write(1, "sa\n", 3);
}

void	rotate_a(t_ls *head)
{
	int		tmp;

	tmp = head->content;
	while (head->next)
	{
		head->content = head->next->content;
		head = head->next;
	}
	head->content = tmp;
	write(1, "ra\n", 3);
}

t_ls	*reverse_rotate_a(t_ls *head)
{
	t_ls		*last;
	t_ls		*ptr1;
	t_ls		*tmp;

	ptr1 = head;
	last = ft_lstlast(head);
	while (ptr1 && ptr1->next && ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	tmp = head;
	head = last;
	head->next = tmp;
	ptr1->next = NULL;
	write(1, "rra\n", 4);
	return (head);
}

t_ls	*sort_thre_nbr(t_ls *h)
{
	if (h->content > h->next->content && h->next->content
		< h->next->next->content && h->next->next->content > h->content)
		swap_a(h);
	else if (h->content > h->next->content && h->next->content
		> h->next->next->content && h->next->next->content < h->content)
	{	
		swap_a(h);
		h = reverse_rotate_a(h);
	}
	else if (h->content > h->next->content && h->next->content
		< h->next->next->content && h->next->next->content < h->content)
		rotate_a(h);
	else if (h->content < h->next->content && h->next->content
		> h->next->next->content && h->next->next->content > h->content)
	{
		swap_a(h);
		rotate_a(h);
	}
	else if (h->content < h->next->content && h->next->content
		> h->next->next->content && h->next->next->content < h->content)
		h = reverse_rotate_a(h);
	return (h);
}

t_ls *get_min_node(t_ls *head)
{
	t_ls			*min;

	min = head;
	while (head)
	{
		if (min->content > head->content)
			min = head;
		head = head->next;
	}
	return (min);
}


t_ls	*push_a(t_ls *head_a, t_ls *head_b)
{
	t_ls				*tmp;

	if (!head_a || !head_b)
		return (0);
	tmp = head_a->next;
	head_a->next = head_b;
	head_b = head_a;
	head_a = tmp;
	write(1, "pa\n", 1);
	return (head_a);
}

t_ls	*push_b(t_ls *head_a, t_ls *head_b)
{
	t_ls			*tmp;

	if (!head_a || !head_b)
		return (0);
	tmp = head_a->next;
	head_a->next = head_b;
	head_b = head_a;
	head_a = tmp;
	write(1, "pb\n", 1);
	return (head_b);
}

void	get_index_min_to_max(t_ls *head)
{
	int			i;
	t_ls		*min;
	t_ls		*current;

	min = head;
	while (min)
	{
		i = 1;
		current = head;
		while (current)
		{
			if (min->content > current->content)
				i++;
			current = current->next;
		}
		min->index = i;
		min = min->next;
	}
}

void	get_index_for_list(t_ls *head_a)
{
	int			i;

	i = 1;
	while (head_a)
	{
		head_a->count = i;
		i++;
		head_a = head_a->next;
	}
}

void	sort_four_nbr(t_ls *head_a, t_ls *head_b, int ac)
{
	head_b = head_a;
	(void)ac;
	get_index_min_to_max(head_a);
	get_index_for_list(head_a);
	while (head_a)
	{
		printf("node %d count --> %d\n", head_a->content, head_a->count);
		head_a = head_a->next;
	}
	printf("\n\n\n\n");
	while (head_b)
	{
		printf("node %d index --> %d\n", head_b->content, head_b->index);
		head_b = head_b->next;
	}
}

t_ls	*algo_sort(t_ls *head_a, t_ls *head_b, int ac)
{
	if (ac == 2)
		swap_a(head_a);
	else if	(ac == 3)
		head_a = sort_thre_nbr(head_a);
	else if (ac == 4)
	{
		sort_four_nbr(head_a, head_b, ac);
	}
	return (head_a);
}

int	main(int ac, char **av)
{
	t_ls		*head_a;
	t_ls		*head_b;

	head_b = NULL;
	if (ac == 1)
		return (0);
	head_a = check_parsing(av);
	get_index_min_to_max(head_a);
	ac = ft_lstsize(head_a);
	// head_b = ft_create_new_node(head_b, ac);
	head_a = algo_sort(head_a, head_b, ac);
	// while (head_a)
	// {
	// 	printf("node --> %d\n", head_a->content);
	// 	head_a = head_a->next;
	// }
}
