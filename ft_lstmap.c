/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:00:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/10 01:03:01 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ls	*ft_lstmap(t_ls *lst, void *(*f)(int), void (*del)(int))
{
	t_ls						*new;
	t_ls						*paste;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		paste = ft_lstnew(f(lst->content));
		if (!paste)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, paste);
		lst = lst->next;
	}
	return (new);
}
