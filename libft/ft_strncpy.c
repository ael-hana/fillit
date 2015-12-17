/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:40:47 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/02 11:56:20 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*d_str;

	d_str = dst;
	while (n && *src)
	{
		*d_str++ = *src++;
		n--;
	}
	ft_bzero(d_str, n);
	return (dst);
}
