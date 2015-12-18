/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:24:04 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/18 08:35:07 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			check_maguel(char **tab, t_err e)
{
	char		minos;

	minos = 0;
	e.i = -1;
	while (tab[++e.i])
	{
		e.j = 0;
		while (tab[e.i][e.j])
		{
			if (((e.j + 1) < 4) && (tab[e.i][e.j + 1] == '#'))
				minos++;
			else if (((e.j - 1) > -1) && (tab[e.i][e.j - 1] == '#'))
				minos++;
			else if (((e.i + 1) < 4) && (tab[e.i + 1][e.j] == '#'))
				minos++;
			else if (((e.i - 1) > -1) && (tab[e.i - 1][e.j] == '#'))
				minos++;
			else if (tab[e.i][e.j] == '#')
				return (-1);
			e.j++;
		}
	}
	return (minos);
}
