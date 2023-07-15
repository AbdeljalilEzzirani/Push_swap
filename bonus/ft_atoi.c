/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:04:11 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 13:45:07 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(2);
}

void	check_over_flow(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error("Error\n");
}

int	ft_atoi(const char *str)
{
	int			i;
	int			fact;
	long		rst;

	i = 0;
	fact = 1;
	rst = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (!str[i + 1])
			ft_error("Error\n");
		if (str[i] == '-')
			fact = fact * (-1);
		if ((str[i + 1] == '+' || str[i + 1] == '-'))
			ft_error("Error\n");
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		rst = (rst * 10) + fact * (str[i++] - 48);
	if (str[i] && !(str[i] >= 48 && str[i] <= 57))
		ft_error("Error\n");
	check_over_flow(rst);
	return (rst);
}
