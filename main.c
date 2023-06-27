/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:38 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/27 01:35:07 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//dst = ft_strdup(" ");
// int parsing(char *str)
// {
				// k = ft_strlen(av[i]);
				// dst = ft_strjoin(av[i], " ");
				// dst = (char *) malloc ((k + 1) * sizeof(char));
				// if (dst == NULL)
				// 	return (0);
// 	ft_strjoin(" ", str);
// 	return (0);
// }

int	main(int ac, char **av)
{
	int			i;
	char		**str;
	int			j;
	int			n;
	t_list		rslt;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			str = ft_split(av[i], ' ');
			j = ft_strlen((const char *)str);
			printf(" atoi --> %d \n", n);
			while (str[j])
			{
				n = atoi((char *) str[j]);
				printf(" atoi --> %d \n", n);
				j--;
			}
			i++;
		}
		printf("\n<< succes >> \n");
	}
	else
		ft_putstr_fd("Error \n", 2);
}
