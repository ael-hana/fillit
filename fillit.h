/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:56:52 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/15 11:01:53 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef	struct		s_tetra
{
	char			*minos;
	int				nb[3];
	struct s_tetra	*next;
}					t_tetra;

typedef struct		s_tab
{
	int				cd[2];
	int				sharp;
	char			**tab;
	int				y;
	int				x;
	int				init;
	int				len;
}					t_tab;

typedef struct		s_err
{
	int				len;
	int				height;
	int				sharp;
	int				i;
	int				j;
}					t_err;

void				print_error(const char *str, t_tetra *list);
int					check_arg(int ac, char **av, int fd);
int					check_tab(int *tab, int check);
void				check_file(t_tetra **list, int fd, t_err e);
int					check_shape(char *str, t_err e, char **minos);
void				check_shape2(t_err e, char **minos, int *nb);
void				init_err(t_err *e);
int					find_first_pos(char **str);
int					check_minos(t_tetra *list, t_err e);
void				list_push_back(t_tetra **list, char *minos);
t_tetra				*create_elem(char *minos);
int					ln(char *str);
char				**split_tab(char *minos, char **str, int *tab);
int					sort(t_tetra *list, char **str, int pos, char c);
int					rc(t_tab i, char **str, char c);
void				ft_remove(char **tab, char chr);
int					ft_resolver(t_tetra *m, char **tab, int x, char chr);
char				**ft_backtracking(t_tetra *list);
void				init_tab(int *tab);
void				ft_print(char **tab);
char				**create_mp(int x);
t_tetra				*ft_free_list(t_tetra *list);

#endif
