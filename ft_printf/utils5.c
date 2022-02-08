/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:10:35 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:10:37 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero(t_struct *flags, char *num_str)
{
	while(flags->prec - ft_strlen(num_str) > 0)
	{
		ft_putchar('0', flags);
		flags->prec--;
	}
}

void	print_zero_space(t_struct *flags, int len)
{
	while (flags->width && (flags->width - len) > 0)
	{
		if (flags->zero == 1 && flags->prec == -1)
			ft_putchar('0', flags);
		else
			ft_putchar(' ', flags);
		flags->width--;
	}
}

void	print_int_minus(t_struct *flags, char *num_str, int len)
{
	if (flags->prec >= 0 && flags->prec > ft_strlen(num_str))
	{
		print_zero(flags, num_str);
		ft_putstr(num_str, flags);
	}
	else
		ft_putstr(num_str, flags);
	print_space(flags, len);
}

void	print_int(t_struct *flags, int num, char *num_str, int len)
{
	if (num < 0 && flags->zero == 1 && flags->prec == -1)
		ft_putchar('-', flags);
	print_zero_space(flags, len);
	if (flags->prec >= 0 && flags->prec > ft_strlen(num_str))
	{
		if (num < 0)
			ft_putchar('-', flags);
		print_zero(flags, num_str);
		ft_putstr(num_str, flags);
	}
	else if (flags->prec >= 0 && flags->prec < ft_strlen(num_str))
	{
		if (num < 0)
			ft_putchar('-', flags);
		ft_putstr(num_str, flags);	
	}
	else
	{
		if (num < 0 && flags->zero == 0)
			ft_putchar('-', flags);
		ft_putstr(num_str, flags);
	}
}

void	process_unsigned(t_struct *flags, va_list argm)
{
	char			*num_str;
	unsigned int	num; 
	int 			len;
	
	num = va_arg(argm, unsigned int);
	if (flags->prec == 0 && num == 0) 
	{
		while (flags->width--)
			ft_putchar(' ', flags);
		return ;
	}
	num_str = ft_utoa_base(num, 10); 
	if (flags->prec > ft_strlen(num_str))
		len = flags->prec;
	else
		len = ft_strlen(num_str);
	print_uns_hex(flags, num_str, len);
}