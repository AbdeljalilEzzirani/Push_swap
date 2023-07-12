/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:54:06 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/12 07:32:09 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	while (head->next)
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
		ft_error("Error 4");
	if (check_sorted(head) == 1)
		exit(0);
}

t_ls	*check_parsing(char **av)
{
	t_ls		*head;
	t_list		var;

	head = NULL;
	var.i = 1;
	while (av[var.i])
	{
		var.str = ft_split(av[var.i], ' ');
		var.j = 0;
		while (var.str[var.j])
		{
			if ((int)var.str[var.j] < 48 && (int)var.str[var.j] > 57)
				ft_error("Error 5");
			add_number(&head, ft_atoi((char *) var.str[var.j]));
			var.j++;
		}
		var.i++;
	}
	duplicate_sorted(head);
	return (head);
}
