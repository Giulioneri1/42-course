/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:10:27 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:10:28 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_base(unsigned long int n, int base)
{
	char	*dec;
	char	*hex;
	char	*ptr;
	char	*str;
	int		len;

	dec = "0123456789";
	hex = "0123456789abcdef";
	len = num_lenght(n, base);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = base == 10 ? dec : hex;
	str[len] = 0;
	while (len)
	{
		str[--len] = ptr[n % base];
		n = n / base;
	}
	return(str);
}

char	*ft_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	print_space(t_struct *flags, int len)
{
	while (flags->width && (flags->width - len) > 0)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
}

int		value_len_str(t_struct *flags, char *arg, int len)
{
	if (arg == NULL)          //lunghezza (null) in base alla prec
	{
		if (flags->prec <= -1)
			len = 6;
		else
			len = flags->prec > 6 ? 6 : flags->prec;
	} 
	else if (flags->prec <= -1)
		len = ft_strlen(arg);
	else
		len = flags->prec > ft_strlen(arg) ? ft_strlen(arg) : flags->prec;
	return (len);
}

int		value_len_int(t_struct *flags, int num, char *num_str)
{
	int len;

	if (flags->prec == -1)
		len = num >= 0 ? ft_strlen(num_str) : ft_strlen(num_str) + 1;
	else if (flags->prec > ft_strlen(num_str))
		len = num >= 0 ? flags->prec : flags->prec + 1;
	else
		len = num >= 0 ? ft_strlen(num_str) : ft_strlen(num_str) + 1;
	return (len);
}
