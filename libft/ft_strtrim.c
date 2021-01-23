/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:47:09 by gneri             #+#    #+#             */
/*   Updated: 2021/01/17 11:47:12 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_char(char const *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*start;
	char	*end;
	char	*tmp;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + (ft_strlen(s1) - 1);
	while (*start && ft_check_char(set, *start))
		start++;
	while (end > start && ft_check_char(set, *end))
		end--;
	if (!(ptr = malloc(sizeof(char) * (end - start + 1) + 1)))
		return (NULL);
	tmp = ptr;
	while (start <= end)
		*ptr++ = *start++;
	*ptr = '\0';
	return (tmp);
}
