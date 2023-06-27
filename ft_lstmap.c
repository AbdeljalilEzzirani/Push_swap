/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:00:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/27 00:36:17 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list						*new;
	t_list						*paste;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	lst = lst -> next;
	while (lst)
	{
		paste = ft_lstnew(f(lst -> content));
		if (!paste)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, paste);
		lst = lst -> next;
	}
	return (new);
}
