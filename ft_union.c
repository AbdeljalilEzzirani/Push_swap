/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:06:39 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/13 22:46:37 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
