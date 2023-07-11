/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/11 03:31:31 by abez-zir         ###   ########.fr       */
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

t_ls	*algo_sort(int ac, t_ls *head)
{
	if (ac == 2)
		swap_a(head);
	else if	(ac == 3)
		head = sort_thre_nbr(head);
	// else if (ac == 5)
	// else if ()
	// else if ()
	return (head);
}

int	main(int ac, char **av)
{
	t_ls		*head;

	if (ac == 1)
		return (0);
	head = check_parsing(av);
	ac = ft_lstsize(head);
	head = algo_sort(ac, head);
	printf("\n\n\n\n");
	while (head)
	{
		printf("node --> %d\n", head->content);
		head = head->next;
	}
}
