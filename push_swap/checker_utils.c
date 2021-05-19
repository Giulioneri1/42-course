/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:15 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:16 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoinumb(char *str, long int i, long int sign, t_num **stack_a)
{
	long int	number;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	number = number * sign;
	if (number > 2147483647 || number < -2147483648)
		ft_error(stack_a);
	return (number);
}

int	ft_atoi(char *str, t_num **stack_a)
{
	long int	i;
	long int	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}	
	res = ft_atoinumb(str, i, sign, stack_a);
	return ((int)res);
}

int	ft_count_words(char *str, char c)
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

char	*ft_malloc_word(char *str, char c)
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
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
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
	words = ft_count_words((char *)s, c);
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			*ptr++ = ft_malloc_word((char *)s, c);
			while (*s && *s != c)
				s++;
		}
	}
	*ptr = NULL;
	return (tmp);
}
