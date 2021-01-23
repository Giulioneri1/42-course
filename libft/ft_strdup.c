/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:38:20 by gneri             #+#    #+#             */
/*   Updated: 2021/01/15 18:56:19 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*temp;

	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	temp = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (temp);
}
