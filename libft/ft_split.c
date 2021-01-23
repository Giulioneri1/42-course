/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:08:14 by gneri             #+#    #+#             */
/*   Updated: 2021/01/17 18:08:17 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char c)
{
	char	*ptr;
	char	*tmp1;
	char	*tmp2;
	size_t	count;

	count = 0;
	tmp1 = str;
	while (*str && *str != c)
	{
		count++;
		str++;
	}
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	tmp2 = ptr;
	while (*tmp1 && *tmp1 != c)
		*ptr++ = *tmp1++;
	*ptr = '\0';
	return (tmp2);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	**tmp;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	if (!(ptr = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	tmp = ptr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			*ptr++ = malloc_word((char *)s, c);
			while (*s && *s != c)
				s++;
		}
	}
	*ptr = NULL;
	return (tmp);
}
