/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:18:33 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/14 11:26:31 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			list_push_back(t_tetra **list, char *minos)
{
	t_tetra		*tmp;

	tmp = *list;
	if (*list == NULL)
		*list = create_elem(minos);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_elem(minos);
	}
}

t_tetra			*create_elem(char *minos)
{
	t_tetra		*tmp;

	if ((tmp = (t_tetra *)malloc(sizeof(t_tetra))) == NULL)
		return (NULL);
	tmp->minos = ft_strdup(minos);
	tmp->next = NULL;
	tmp->nb[0] = 0;
	tmp->nb[1] = 0;
	tmp->nb[2] = -1;
	return (tmp);
}

t_tetra			*ft_free_list(t_tetra *list)
{
	t_tetra		*tmp;

	if (list == NULL)
		return (NULL);
	tmp = list->next;
	free(list);
	return (ft_free_list(tmp));
}
