/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:56:50 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/27 11:33:29 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

int	ft_strnstr(const char *hay, const char *ndl)
{
	size_t i;
	size_t j;

	if (*ndl == '\0')
		return (0);
	i = 0;
	while (*(hay + i) != '\0')
	{
		j = 0;
		while (*(hay + i + j) == *(ndl + j))
		{
			if (*(ndl + j + 1) == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}