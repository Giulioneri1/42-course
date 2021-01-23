/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:05:02 by gneri             #+#    #+#             */
/*   Updated: 2021/01/18 17:05:06 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		num_lenght(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	char	*tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = n >= 0 ? num_lenght(n) : num_lenght(n) + 1;
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = ptr + len;
	*tmp = 0;
	if (n == 0)
		*--tmp = '0';
	if (n < 0)
	{
		n *= -1;
		*ptr = '-';
	}
	while (n > 0)
	{
		*--tmp = (n % 10) + '0';
		n = n / 10;
	}
	return (ptr);
}
