/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/04 21:10:07 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_parsing(char *str)
{
	t_list		set;

	set.str = ft_split(&str[set.i], ' ');
	set.j = 0;
	while (set.str[set.j])
	{
		if ((int)set.str[set.j] < 48 && (int)set.str[set.j] > 57)
		{
			ft_putstr_fd("ERrOr! \n", 2);
			exit(1);
		}
		set.n = ft_atoi((char *) set.str[set.j]);
		printf("---.result atoi %d \n", set.n);
		set.j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list		set;

	set.i = 1;
	if (ac > 1)
	{
		while (av[set.i])
		{
			check_parsing(av[set.i]);
			set.i++;
		}
		printf("\n<< succes >> \n");
	}
	else
		ft_putstr_fd("Error \n", 2);
}
