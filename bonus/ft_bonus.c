/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:31:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 16:06:20 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
	else if (ac <= 100)
		sort_one_hundred(head_a, head_b, ac);
	else if (ac <= 500)
		sort_five_hundred(head_a, head_b, ac);
	return ((*head_a));
}
