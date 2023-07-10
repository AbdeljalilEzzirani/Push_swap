/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/10 03:56:30 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_ls **head, int num)
{
	if ((*head) == NULL)
	{
		(*head) = ft_lstnew(num);
	}
	else
		ft_lstadd_back(head, ft_lstnew(num));
}

int	check_sorted(t_ls *head)
{
	while (head->next)
	{
		if (head->content < head->next->content)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

int	check_duplicate(t_ls *head)
{
	t_ls	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (tmp->content == head->content)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

void	duplicate_sorted(t_ls *head)
{
	if (check_duplicate(head) == 1)
		ft_error();
	if (check_sorted(head) == 1)
		ft_error();
}

int	check_parsing(int ac, char **av)
{
	t_ls		*head;
	t_list		var;

	head = NULL;
	var.i = 1;
	if (ac > 1)
	{
		while (av[var.i])
		{
			var.str = ft_split(av[var.i], ' ');
			var.j = 0;
			while (var.str[var.j])
			{
				if ((int)var.str[var.j] < 48 && (int)var.str[var.j] > 57)
					ft_error();
				add_number(&head, ft_atoi((char *) var.str[var.j]));
				var.j++;
			}
			var.i++;
		}
	}
	else
		ft_error();
	duplicate_sorted(head);
	return (0);
}


int	main(int ac, char **av)
{
	check_parsing(ac, av);
}
