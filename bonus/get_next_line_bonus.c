/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:54:54 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/17 20:54:56 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line_bonus(int fd)
{
	char					*rslt;
	static char				*biit_lkhziin[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &rslt, 0) < 0)
	{
		if (biit_lkhziin[fd])
		{
			free(biit_lkhziin[fd]);
			biit_lkhziin[fd] = NULL;
		}
		return (NULL);
	}
	biit_lkhziin[fd] = read_line(fd, biit_lkhziin[fd]);
	if (!biit_lkhziin[fd])
		return (NULL);
	rslt = push_line(biit_lkhziin[fd]);
	if (!rslt)
		return (NULL);
	biit_lkhziin[fd] = sauvgard_line(biit_lkhziin[fd]);
	return (rslt);
}

// int main()
// {
// 	int fd0 = open ("check.txt", O_RDONLY);
// 	int fd1 = open ("test.txt", O_RDONLY);
// 	// char *src;
// 	// char *dst;

// 	// src = get_next_line_bonus(fd[0]);
// 	// dst = get_next_line_bonus(fd0[0]);
// 	// printf("%s \n", src);
// 	// printf("%s \n", dst);
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	printf("||%s|| \n", get_next_line_bonus(fd0));
// 	printf("||%s|| \n", get_next_line_bonus(fd1));
// 	// printf("||%s|| \n", get_next_line_bonus(fd0));
// 	// printf("||%s|| \n", get_next_line_bonus(fd0));
// 	// printf("||%s|| \n", get_next_line_bonus(fd0));
// 	// printf("||%s|| \n", get_next_line_bonus(fd0));
// 	close(fd0);
// 	close(fd1);
// }
