/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/18 22:29:15 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_slash_n(char *str)
{
	int					i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*push_line(char *str)
{
	int				i;
	int				j;
	char			*chereen;

	i = ft_count_len_line(str);
	if (ft_find_slash_n(str) == 0)
		i++;
	else
		i += 2;
	chereen = (char *) malloc (i * sizeof(char));
	if (NULL == chereen)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		chereen[j] = str[i];
		i++;
		j++;
	}
	if (str[i] == '\n')
		chereen[j++] = '\n';
	chereen[j] = '\0';
	return (chereen);
}

static char	*sauvgard_line(char *str)
{
	int							i;
	int							j;
	char						*sauvgard;

	i = 0;
	sauvgard = (char *) malloc ((ft_strlen(str) - ft_count_len_line(str)) + 1);
	if (NULL == sauvgard)
		return (free(str), free(sauvgard), NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
				sauvgard[j++] = str[i++];
	}
	sauvgard[j] = '\0';
	if (j == 0)
		return (free(str), free(sauvgard), NULL);
	return (sauvgard[j] = '\0', free(str), sauvgard);
}

static char	*read_line(int fd, char *biit_lkhziin)
{
	char					*buf;
	int						i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buf)
		return (free(buf), free(biit_lkhziin), NULL);
	i = 1;
	while (ft_find_slash_n(biit_lkhziin) == 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (free(buf), free(biit_lkhziin), NULL);
		buf[i] = '\0';
		if (i == 0)
			return (free(buf), biit_lkhziin);
		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
	}
	return (free(buf), biit_lkhziin);
}

char	*get_next_line(int fd)
{
	char					*rslt;
	static char				*biit_lkhziin;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &rslt, 0) < 0)
	{
		if (biit_lkhziin)
		{
			free(biit_lkhziin);
			biit_lkhziin = NULL;
		}
		return (NULL);
	}
	biit_lkhziin = read_line(fd, biit_lkhziin);
	if (!biit_lkhziin)
		return (NULL);
	rslt = push_line(biit_lkhziin);
	if (!rslt)
		return (NULL);
	biit_lkhziin = sauvgard_line(biit_lkhziin);
	return (rslt);
}

// // // void	leaks(){system("leaks a.out");}
// int main()
// {
// 	int fd = open("check.txt", O_RDWR);
// 	// char *str;
// 	// str = get_next_line(fd);
// 	// while (str != NULL)
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }
// 	// printf("||%s|| \n", get_next_line(42));
// 	// printf("||%s|| \n", get_next_line(100));
// 	// printf("||%s|| \n", get_next_line(99));
// 	int a = 0;
// 	while(a < 10){
// 	printf("||%s|| \n", get_next_line(fd));
// 	a++;
// 	}
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// 	// printf("||%s|| \n", get_next_line(0));
// }
