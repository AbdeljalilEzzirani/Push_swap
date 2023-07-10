/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:04:11 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/10 03:52:05 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

// void	check_over_flow(int nbr) //mekhadamach 3elach llaho a3elaam
// {
// 	if (nbr > 2147483647 || nbr > -2147483648)
// 	{
// 		printf("over flow \n");
// 		ft_error();
// 	}
// }

int	ft_atoi(const char *str)
{
	int						i;
	int						fact;
	long					rst;

	i = 0;
	fact = 1;
	rst = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (!str[i + 1])
			ft_error();
		if (str[i] == '-')
			fact = fact * (-1);
		if ((str[i + 1] == '+' || str[i + 1] == '-'))
			ft_error();
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		rst = (rst * 10) + fact * (str[i++] - 48);
	if (str[i] && !(str[i] >= 48 && str[i] <= 57))
		ft_error();
	// printf("check ->> %ld \n", rst);
	// check_over_flow(rst);
	return (rst);
}
