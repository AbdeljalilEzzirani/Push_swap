/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 15:36:58 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_ls	*sort_thre_nbr(t_ls **h)
{
	if ((*h)->contnt > (*h)->next->contnt && (*h)->next->contnt
		< (*h)->next->next->contnt && (*h)->next->next->contnt > (*h)->contnt)
		swap_a(h);
	else if ((*h)->contnt > (*h)->next->contnt && (*h)->next->contnt
		> (*h)->next->next->contnt && (*h)->next->next->contnt < (*h)->contnt)
	{
		swap_a(h);
		(*h) = reverse_rotate_a(h);
	}
	else if ((*h)->contnt > (*h)->next->contnt && (*h)->next->contnt
		< (*h)->next->next->contnt && (*h)->next->next->contnt < (*h)->contnt)
		rotate_a(h);
	else if ((*h)->contnt < (*h)->next->contnt && (*h)->next->contnt
		> (*h)->next->next->contnt && (*h)->next->next->contnt > (*h)->contnt)
	{
		swap_a(h);
		rotate_a(h);
	}
	else if ((*h)->contnt < (*h)->next->contnt && (*h)->next->contnt
		> (*h)->next->next->contnt && (*h)->next->next->contnt < (*h)->contnt)
		(*h) = reverse_rotate_a(h);
	return (*h);
}

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

void	check_strccmp(t_ls **stack_a, t_ls **stack_b, char *input)
{
	if (ft_strncmp(input, "rra\n", 3) == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strncmp(input, "rrb\n", 3) == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(input, "ss\n", 2) == 0)
		swap_a_swap_b(stack_a, stack_b);
	else if (ft_strncmp(input, "rrr\n", 3) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(input, "rr\n", 2) == 0)
		rotate_a_rotate_b(stack_a, stack_b);
	else if (ft_strncmp(input, "sa\n", 2) == 0)
		swap_a(stack_a);
	else if (ft_strncmp(input, "sb\n", 2) == 0)
		swap_a(stack_b);
	else if (ft_strncmp(input, "pa\n", 2) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(input, "pb\n", 2) == 0)
		push_b(stack_a, stack_b);
	else if (ft_strncmp(input, "ra\n", 2) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(input, "rb\n", 2) == 0)
		rotate_b(stack_b);
	else
		ft_error("Error\n");
}

int	main(int ac, char **av)
{
	t_ls		*head_a;
	t_ls		*head_b;
	char		*input;

	if (ac == 1)
		return (0);
	head_b = NULL;
	head_a = check_parsing(av);
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		check_strccmp(&head_a, &head_b, input);
		free(input);
	}
	if (head_b == NULL && check_sorted(head_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
