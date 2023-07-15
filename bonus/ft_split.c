/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:49:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/07/15 13:47:48 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	count_nbr_case_in_tab(char const *s, char c)
{
	int			nbr;
	int			i;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			nbr = nbr + 1;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nbr);
}

static void	free_tab(char **s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**ft_lkhedma(const char *s, char **tab, int nbr, char c)
{
	int				i;
	int				j;
	int				swap;

	i = 0;
	j = 0;
	while (s[i] && j < nbr)
	{
		while (s[i] == c)
			i++;
		swap = i;
		while (s[i] != c)
			i++;
		tab[j] = ft_substr(s, swap, (i - swap));
		if (tab[j] == NULL)
		{
			free_tab(tab);
			return (NULL);
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	int			nbr;

	if (!s)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	nbr = count_nbr_case_in_tab(s, c);
	if (nbr == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	tab = (char **)malloc(sizeof(char *) * (nbr + 1));
	if (tab == NULL)
		return (NULL);
	return (ft_lkhedma(s, tab, nbr, c));
}
