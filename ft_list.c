/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:08:48 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/11 00:24:52 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_ls **head, int num)
{
	if ((*head) == NULL)
	{
		(*head) = ft_lstnew(num);
	}
	else
		ft_lstadd_back(head, ft_lstnew(num));
}

t_ls	*ft_lstnew(int content)
{
	t_ls					*node;

	node = (t_ls *) malloc(sizeof(t_ls));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_ls **lst, t_ls *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		return (ft_lstadd_front(lst, new));
	ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_ls **lst, t_ls *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_ls	*ft_lstlast(t_ls *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
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
