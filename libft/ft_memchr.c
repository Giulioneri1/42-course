/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:34:49 by gneri             #+#    #+#             */
/*   Updated: 2021/01/13 11:49:42 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;

	src = (unsigned char *)s;
	while (n > 0)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
