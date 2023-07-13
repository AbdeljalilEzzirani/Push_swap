/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:31:04 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/13 22:06:57 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int					i;

	// if (s == NULL)
	// 	return (NULL);
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}