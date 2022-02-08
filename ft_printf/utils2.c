/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:01:13 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:01:21 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_char(t_struct *flags, va_list argm) 
{
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			ft_putchar(va_arg(argm, int), flags);
			while (flags->width-- > 1)
				ft_putchar(' ', flags);
		}
		else
		{
			while(flags->width-- > 1)
				ft_putchar(' ', flags);
			ft_putchar(va_arg(argm, int), flags);
		}
	}
	else
		ft_putchar(va_arg(argm, int), flags);
} 

void	process_percent(t_struct *flags)
{
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			ft_putchar('%', flags);
			while (flags->width-- > 1)
				ft_putchar(' ', flags);
		}
		else
		{
			while(flags->width-- > 1)
			{
				if (flags->zero == 1)
					ft_putchar('0', flags);
				else
					ft_putchar(' ', flags);
			}
			ft_putchar('%', flags);
		}
	}
	else
		ft_putchar('%', flags);
}

void	process_string(t_struct *flags, va_list argm)
{
	char *arg;
	int len;

	len = 0;
	arg = va_arg(argm, char *);
	len = value_len_str(flags, arg, len);
	if (flags->minus == 1)
	{
		if (arg == NULL)
			ft_putstr_str("(null)", flags, len);
		else
			ft_putstr_str(arg, flags, len);
		print_space(flags, len);
	}
	else
	{
		print_space(flags, len);
		if (arg == NULL)
			ft_putstr_str("(null)", flags, len);
		else
			ft_putstr_str(arg, flags, len);
	}
}

void	process_integer(t_struct *flags , va_list argm)
{
	char *num_str;
	int num; 
	int len;
	
	num = va_arg(argm, int);
	if (flags->prec == 0 && num == 0)
	{
		while (flags->width--)
			ft_putchar(' ', flags);
		return ;
	}
	num_str = ft_itoa(num);
	len = value_len_int(flags, num, num_str);
	if (flags->minus == 1)
	{
		if (num < 0)
			ft_putchar('-', flags);
		print_int_minus(flags, num_str, len);
	}
	else
		print_int(flags, num, num_str, len);
}

void	print_uns_hex(t_struct *flags, char *num_str, int len)
{
	if (flags->minus == 1) 
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
	else 
	{
		print_zero_space(flags, len);
		if (flags->prec >= 0 && flags->prec > ft_strlen(num_str))
		{
			print_zero(flags, num_str);
			ft_putstr(num_str, flags);
		}
		else
			ft_putstr(num_str, flags);
	}
}