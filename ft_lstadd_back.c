/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:24:02 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/10 00:52:27 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_ls **lst, t_ls *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		return (ft_lstadd_front(lst, new));
	ft_lstlast(*lst)->next = new;
}
