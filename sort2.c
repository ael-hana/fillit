/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:41:38 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/15 13:32:56 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ln(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i - 1);
}

char				**split_tab(char *minos, char **str, int *tab)
{
	int				i;
	int				j;

	tab[0] = 0;
	tab[1] = 0;
	i = 0;
	j = 0;
	str = ft_strsplit(minos, '\n');
	while (str[i][j] != '#')
	{
		j = 0;
		while (str[i][j] != '\0' && str[i][j] != '#')
		{
			tab[1]++;
			j++;
		}
		if (str[i][j] != '#')
		{
			tab[1] = 0;
			tab[0]++;
			i++;
		}
	}
	return (str);
}

int					sort(t_tetra *list, char **str, int pos, char c)
{
	t_tab			i;

	i.tab = split_tab(list->minos, i.tab, i.cd);
	i.y = pos % 100;
	i.x = pos / 100;
	i.len = i.cd[1];
	i.init = i.y;
	i.sharp = 0;
	if (list->nb[0] + i.x > ln(*str) + 1)
		return (-1);
	if ((i.y - list->nb[2]) + 1 < 0)
		return (-1);
	if (i.y + ((list->nb[2] - list->nb[1]) * -1) > ln(*str))
		return (-1);
	if (rc(i, str, c) == -1)
		return (-1);
	else
		return (0);
}

int					rc(t_tab i, char **str, char c)
{
	while (i.sharp != 4)
	{
		i.tab[i.cd[0]][i.cd[1]] == '.' ? i.cd[1]++ : (i.sharp = i.sharp);
		if (i.tab[i.cd[0]][i.cd[1]] == '\0')
		{
			i.cd[0]++;
			i.cd[1] = 0;
			i.x++;
		}
		if (i.tab[i.cd[0]][i.cd[1]] == '#')
		{
			i.y = i.init;
			i.y += ft_find_diff(i.len, i.cd[1]);
			if (str[i.x][i.y] == '.')
				str[i.x][i.y] = c;
			else
				return (-1);
			i.sharp++;
		}
		i.cd[1]++;
	}
	return (0);
}
