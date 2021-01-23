/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:56:30 by gneri             #+#    #+#             */
/*   Updated: 2021/01/13 11:50:22 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sour;

	dest = dst;
	sour = (unsigned char *)src;
	if (!dest && !sour)
		return (NULL);
	if (sour < dest)
	{
		while (len > 0)
		{
			len--;
			dest[len] = sour[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*dest++ = *sour++;
			len--;
		}
	}
	return (dst);
}
