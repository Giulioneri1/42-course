/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:01:27 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:01:29 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\f' || c == '\r' || c == '\v');
}

int		num_lenght(long int n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *s1)
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

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	char	*tmp;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	len = num_lenght(n, 10);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = ptr + len;
	*tmp = 0;
	if (n == 0)
		*--tmp = '0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		*--tmp = (n % 10) + '0';
		n = n / 10;
	}
	return (ptr);
}

void	init_struct(t_struct *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->type = 0;
}