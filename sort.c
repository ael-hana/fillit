/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_de_fou_comme_sa_killan_se          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:52:12 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/17 16:02:11 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_remove(char **tab, char chr)
{
	int				x;
	int				y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == chr)
				tab[x][y] = '.';
			y++;
		}
		x++;
	}
}

char				**create_mp(int x)
{
	char			**tab;
	int				i;
	int				j;

	if (x < 4)
		x = 4;
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (x + 1))))
		return (NULL);
	tab[x] = NULL;
	while (i < x)
	{
		j = 0;
		if (!(tab[i] = (char *)ft_memalloc(sizeof(char) * (x + 2))))
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		while (j < x)
			tab[i][j++] = '.';
		tab[i++][j] = '\n';
	}
	return (tab);
}

char				**ft_backtracking(t_tetra *list)
{
	int				num;
	char			**tab;
	int				i;
	t_tetra			*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	num = ft_rootnb((i * 4));
	tab = create_mp(num);
	while (ft_resolver(list, tab, 0, 'A'))
	{
		ft_free_tab(tab);
		num++;
		tab = create_mp(num);
	}
	return (tab);
}

int					ft_resolver(t_tetra *m, char **tab, int x, char chr)
{
	int				y;

	if (!m)
		return (0);
	while (tab[x])
	{
		y = 0;
		while (tab[x][y] != '\n')
		{
			while ((sort(m, tab, ((x * 100) + y), chr)) && tab[x][y] != '\n')
			{
				ft_remove(tab, chr);
				y += 1;
			}
			if (tab[x][y] != '\n' && (!(ft_resolver(m->next, tab, 0, chr + 1))))
				return (0);
			ft_remove(tab, chr);
			if (tab[x][y] != '\n')
				y += 1;
		}
		x += 1;
	}
	return (-1);
}
