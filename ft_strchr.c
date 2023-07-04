/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:04:07 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/04 19:33:08 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((char )c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)&s[i]);
	return (NULL);
}
