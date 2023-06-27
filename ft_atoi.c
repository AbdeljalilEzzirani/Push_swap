/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:04:11 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/26 19:33:22 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
