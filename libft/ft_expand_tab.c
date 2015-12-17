/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:58:16 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/08 16:22:39 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_expand_tab(char **str, int nb)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	if (!str)
		return (NULL);
	if (!(tmp = ft_create_tab(nb)))
		return (NULL);
	while (str[i])
	{
		ft_strcpy(tmp[i], str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (tmp);
}
