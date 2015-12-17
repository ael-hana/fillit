/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:26:39 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/15 13:31:02 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				print_error(const char *str, t_tetra *list)
{
	if (list != NULL)
		ft_free_list(list);
	ft_putstr("error");
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int					find_first_pos(char **str)
{
	int				i;
	int				j;
	int				pos;

	pos = -1;
	j = 0;
	while (pos == -1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i][j] == '#')
				pos = j;
			i++;
		}
		j++;
	}
	return (pos);
}

void				init_err(t_err *e)
{
	e->len = 0;
	e->height = 0;
	e->sharp = 0;
	e->i = -1;
	e->j = -1;
}

int					main(int argc, char **argv)
{
	t_tetra			*list;
	int				fd;
	t_err			e;
	char			**tab;

	list = NULL;
	init_err(&e);
	if (argc != 2)
		print_error("\n", NULL);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		print_error("\n", NULL);
	check_file(&list, fd, e);
	close(fd);
	if (check_minos(list, e) == -1)
		print_error("\n", list);
	tab = ft_backtracking(list);
	ft_print_tab(tab);
	ft_free_tab(tab);
	ft_free_list(list);
	return (0);
}
