/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:24:00 by gneri             #+#    #+#             */
/*   Updated: 2021/01/14 11:06:00 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t r;

	i = 0;
	j = 0;
	r = 0;
	while (dst[i] != '\0')
	{
		i++;
		r++;
	}
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] != '\0' && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (r + ft_strlen(src));
}
