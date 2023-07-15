/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:45:51 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 00:40:48 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int	main ()
// {
// 	char r1[]="";
// 	char r2[]="hello";
// 	int				j;
// 	j = ft_strncmp(r1, r2, 9);
// 	printf ("%d\n", j);
// 	char s1[]="";
// 	char s2[]="hello";
// 	int				i;
// 	i = strncmp(s1, s2, 9);
// 	printf ("%d\n", i);
// }
