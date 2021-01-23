/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:35:56 by gneri             #+#    #+#             */
/*   Updated: 2021/01/16 11:35:58 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;
	char	*tmp;

	if (!s || start >= ft_strlen(s))
		return (ptr = malloc(sizeof(char)));
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str = (char *)s + start;
	tmp = ptr;
	while (len--)
		*ptr++ = *str++;
	*ptr = '\0';
	return (tmp);
}
