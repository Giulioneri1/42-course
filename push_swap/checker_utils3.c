/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:30 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:31 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int	i;

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_checkstr(char *str, t_stack *stacks)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' '
			|| (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
}
