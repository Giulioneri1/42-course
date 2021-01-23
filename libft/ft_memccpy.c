/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:34:43 by gneri             #+#    #+#             */
/*   Updated: 2021/01/12 12:47:27 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		if ((unsigned char)c == *ptr2)
		{
			*ptr1 = *ptr2;
			return (ptr1 + 1);
		}
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
