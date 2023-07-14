/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:54:06 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/14 09:17:50 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_ls *head)
{
	while (head->next)
	{
		if (head->contnt < head->next->contnt)
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
			if (tmp->contnt == head->contnt)
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
		ft_error("Error\n");
	if (check_sorted(head) == 1)
		exit(0);
}

char	**free_strr(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
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
			{
				free_strr(var.str);
				ft_error("Error\n");
			}
			add_number(&head, ft_atoi((char *) var.str[var.j]));
			free(var.str[var.j]);
			var.j++;
		}
		free(var.str);
		var.i++;
	}
	duplicate_sorted(head);
	return (head);
}
