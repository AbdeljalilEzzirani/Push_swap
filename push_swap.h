/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:55:01 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/10 02:23:23 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<limits.h>
# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include<stddef.h>

typedef struct s_ls
{
	int				content;
	struct s_ls	*next;
}					t_ls;


typedef struct s_list
{
	int				i;
	char			**str;
	int				j;
}					t_list;

char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dst, const void *src,	size_t n);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(const char *str);
void			ft_error(void);
int				check_duplicate(t_ls *head);
int				check_sorted(t_ls *head);
void			duplicate_sorted(t_ls *head);


void			ft_lstadd_back(t_ls **lst, t_ls *new);
void			ft_lstadd_front(t_ls **lst, t_ls *new);
void			ft_lstclear(t_ls **lst, void (*del)(int));
void			ft_lstdelone(t_ls *lst, void (*del)(int));
void			ft_lstiter(t_ls *lst, void (*f)(int));
t_ls			*ft_lstnew(int content);
t_ls			*ft_lstlast(t_ls *lst);
t_ls			*ft_lstmap(t_ls *lst, void*(*f)(void *), void (*del)(void *));
int				ft_lstsize(t_ls *lst);
char			*ft_strchr(const char *s, int c);
#endif