/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/24 02:31:34 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *s)
{
	int					i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

int atoi(const char *str)
{
	int					i;
	int					fact;
	long				rst;

	i = 0;
	fact = 1;
	rst = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			fact = fact * (-1);
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		rst = (rst * 10) + fact * (str[i] - 48);
		i++;
	}
	return (rst);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (av[i])
			{
				ft_split(av[i], '-');
				j = atoi(av[i]);
				printf("%d  ", j);
			}
			i++;
		}
		printf("\n<< succes >> \n");
	}
	else
		putstr("Error \n");
}
