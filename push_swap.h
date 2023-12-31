/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:55:01 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 16:36:35 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<limits.h>
# include<stddef.h>
# include <stddef.h>

typedef struct s_ls
{
	int				index;
	int				count;
	int				contnt;
	struct s_ls		*next;
}					t_ls;

typedef struct s_list
{
	int				i;
	char			**str;
	int				j;
}					t_list;

char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src,	size_t n);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
void		ft_error(char *str);
int			check_duplicate(t_ls *head);
int			check_sorted(t_ls *head);
void		duplicate_sorted(t_ls *head);
t_ls		*check_parsing(char **av);
void		add_number(t_ls **head, int num);
void		chunk_push_a(t_ls **head_a, t_ls **head_b);
int			get_max(t_ls **head);

void		rotate_a_rotate_b(t_ls **head_a, t_ls **head_b);
void		swap_a(t_ls **head);
void		rotate_a(t_ls **head);
void		rotate_b(t_ls **head_b);
t_ls		*reverse_rotate_a(t_ls **head);

void		push_a(t_ls **head_a, t_ls **head_b);
void		push_b(t_ls **head_a, t_ls **head_b);

void		get_index_for_list(t_ls **head_a);
void		get_index_min_to_max(t_ls **head);

void		check_pos_three_nbr_push(t_ls **head_a, t_ls **head_b, int count);
void		check_pos_four_nbr_push(t_ls **head_a, t_ls **head_b, int count);
void		check_pos_five_nbr_push(t_ls **head_a, t_ls **head_b, int count);
void		sort_one_hundred(t_ls **head_a, t_ls **head_b, int ac);
void		chunk_job(t_ls **head_a, t_ls **head_b, int chunck, int moyenne);
t_ls		*reverse_rotate_b(t_ls **head);
void		sort_five_hundred(t_ls **head_a, t_ls **head_b, int ac);

void		ft_lstadd_back(t_ls **lst, t_ls *new);
void		ft_lstadd_front(t_ls **lst, t_ls *new);
t_ls		*ft_lstnew(int content);
t_ls		*ft_lstlast(t_ls *lst);
int			ft_lstsize(t_ls *lst);

#endif