/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:54:06 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 02:00:48 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int check_sorted(t_ls *head)
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

int check_duplicate(t_ls *head)
{
	t_ls *tmp;

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

void duplicate_sorted(t_ls *head)
{
	if (check_duplicate(head) == 1)
		ft_error("Error\n");
}

char **free_strr(char **string)
{
	int i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
}

void	check_arg(char *arg)
{
	if (ft_strlen(arg) > ft_strlen("+2147483647"))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

t_ls *check_parsing(char **av)
{
	t_ls *head;
	t_list var;
	int i = 0;

	head = NULL;
	var.i = 1;
	while (av[var.i])
	{
		var.str = ft_split(av[var.i], ' ');
		var.j = 0;
		while (var.str[i])
		{
			check_arg(var.str[i]);
			i++;
		}
		while (var.str[var.j])
		{
			if ((int)var.str[var.j] < 48 && (int)var.str[var.j] > 57)
			{
				free_strr(var.str);
				ft_error("Error\n");
			}
			add_number(&head, ft_atoi((char *)var.str[var.j]));
			free(var.str[var.j]);
			var.j++;
		}
		free(var.str);
		var.i++;
	}
	duplicate_sorted(head);
	return (head);
}
