/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:31:04 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/14 08:28:24 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int					i;

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

void	*ft_memcpy(void *dst, const void *src,	size_t n)
{
	size_t					i;
	char					*d;
	const char				*s;

	i = 0;
	s = src;
	d = dst;
	if (s == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

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

char	*ft_strdup(const char *s1)
{
	char			*p;
	int				size;

	if (s1 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	p = (char *) malloc (sizeof(char) * size + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, size);
	p[size] = '\0';
	return (p);
}
