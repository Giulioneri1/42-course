/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:31 by gneri             #+#    #+#             */
/*   Updated: 2021/01/15 18:12:19 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;
	void	*temp;

	len = count * size;
	if (!(ptr = malloc(len)))
		return (NULL);
	temp = ptr;
	while (len--)
	{
		*(char *)ptr = 0;
		ptr++;
	}
	return (temp);
}
