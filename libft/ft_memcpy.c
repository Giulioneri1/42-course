/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:41:20 by gneri             #+#    #+#             */
/*   Updated: 2021/01/12 11:16:38 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	if (!ptr1 && !ptr2)
		return (NULL);
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
		n--;
	}
	return (dst);
}
