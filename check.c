/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:27:43 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/17 16:30:09 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_minos(t_tetra *list, t_err e)
{
	char		**minos;

	init_err(&e);
	minos = ft_strsplit(list->minos, '\n');
	if (check_shape(list->minos, e, minos) == -1)
	{
		ft_free_tab(minos);
		return (-1);
	}
	check_shape2(e, minos, list->nb);
	if ((check_tab(list->nb, 0)) == -1)
	{
		ft_free_tab(minos);
		return (-1);
	}
	ft_free_tab(minos);
	if (list->next)
		return (check_minos(list->next, e));
	return (0);
}

void			check_shape2(t_err e, char **minos, int *nb)
{
	int			coor;
	int			first_pos;

	e.i = -1;
	e.len = 0;
	first_pos = find_first_pos(minos);
	while (minos[++e.i])
	{
		e.j = -1;
		coor = 0;
		while (minos[e.i][++e.j])
		{
			if (minos[e.i][e.j] == '#')
			{
				if (nb[2] == -1)
					nb[2] = ((first_pos - e.j) * -1) + 1;
				if (coor == 0)
					nb[0]++;
				coor++;
				if (nb[1] < ((first_pos - e.j) * -1) + 1)
				{
					nb[1] = ((first_pos - e.j) * -1) + 1;
				printf("first:%d e.j:%d ", first_pos, e.j);
				}
			}
		}
	}
}

int				check_shape(char *str, t_err e, char **minos)
{
	if (str[0] == '\n')
		return (-1);
	while (minos[++e.i])
	{
		e.j = -1;
		e.len = 0;
		while (minos[e.i][++e.j])
		{
			if (minos[e.i][e.j] != '.')
			{
				if (minos[e.i][e.j] == '#')
					e.sharp++;
				else
					return (-1);
				e.len = 1;
			}
		}
		if (e.len == 0 && (e.sharp != 0 && e.sharp != 4))
			return (-1);
		if (e.j != 4)
			return (-1);
	}
	return (e.i == 4 && e.j == 4 && e.sharp == 4 ? 0 : -1);
}

void			check_file(t_tetra **list, int fd, t_err e)
{
	char		buf[21];
	int			ret;
	static	int	perm;

	ret = 1;
	e.i = 0;
	while (ret > 0 && e.i <= 520)
	{
		if ((ret = read(fd, buf, 20)) > 0)
		{
			e.i += ret;
			buf[20] = '\0';
			list_push_back(list, buf);
			perm = 0;
		}
		if ((ret = read(fd, buf, 1)) > 0)
		{
			buf[1] = '\0';
			if (ft_strcmp(buf, "\n") != 0)
				print_error("\n", *list);
			perm = 1;
		}
	}
	if (ret == -1 || e.i > 520  || perm == 1 || e.i == 0)
		print_error("\n", *list);
}

int				check_tab(int *tab, int check)
{
	printf("%d %d", tab[0], tab[1]);
	if (tab[0] == 1)
	{
		if (tab[1] != 4)
			check = 1;
	}
	else if (tab[0] == 2)
	{
		if (tab[1] != 2 && tab[1] != 3)
			check = 1;
	}
	else if (tab[0] == 3)
	{
		if (tab[1] != 2)
			check = 1;
	}
	else if (tab[0] == 4)
	{
		if (tab[1] != 1)
			check = 1;
	}
	else
		check = 1;
	if (check == 1)
		return (-1);
	return (0);
}
