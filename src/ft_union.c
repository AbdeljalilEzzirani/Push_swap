/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:06:39 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 00:24:18 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char							*p;
	size_t							i;
	size_t							j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_strdup(""));
	if (len > j)
		len = j - start;
	p = (char *) malloc (sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	sort_five_hundred(t_ls **head_a, t_ls **head_b, int ac)
{
	int				chunck;
	int				moyenne;

	chunck = ac / 10;
	moyenne = chunck / 2;
	get_index_min_to_max(head_a);
	get_index_for_list(head_a);
	chunk_job(head_a, head_b, chunck, moyenne);
	chunk_push_a(head_a, head_b);
}

int	ft_lstsize(t_ls *lst)
{
	int					i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
