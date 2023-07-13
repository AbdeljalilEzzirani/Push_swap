/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:23:47 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/14 00:22:06 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char			*p;
	int				size;

	if (s1 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	p = (char *) malloc (sizeof(char) * size + 1);
		printf("strdup ---> %p\n", p);

	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, size);
	p[size] = '\0';
	return (p);
}
