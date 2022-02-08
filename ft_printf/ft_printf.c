/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:52:40 by gneri             #+#    #+#             */
/*   Updated: 2021/02/11 16:52:41 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char *f, t_struct *flags)
{
	if (f[flags->i] == '0')
	{
		flags->zero = 1;
		flags->i++;
	}
	if (f[flags->i] == '-')
	{
		flags->minus = 1;
		flags->i++;
	}
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
}

void	check_width(const char *f, t_struct *flags, va_list argm)
{
	if (ft_isdigit(f[flags->i]))
	{
		flags->width = ft_atoi(&f[flags->i]);
		while (ft_isdigit(f[flags->i]))
			flags->i++;
	}
	else if (f[flags->i] == '*')
	{
		flags->width = va_arg(argm, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		flags->i++;
	}
}

void	check_precision(const char *f, t_struct *flags, va_list argm)
{
	if (f[flags->i] != '.')
		return ;
	flags->i++;
	if (ft_isdigit(f[flags->i]))
	{
		flags->prec = ft_atoi(&f[flags->i]);
		while (ft_isdigit(f[flags->i]))
			flags->i++;
	}
	else if (f[flags->i] == '*')
	{
		flags->prec = va_arg(argm, int);
		flags->i++;
	}
	else
		flags->prec = 0;
}

void	process_type(const char *f, t_struct *flags, va_list argm)
{
	int capitalize;

	capitalize = 0;
	if (f[flags->i] == 'c') 
		process_char(flags, argm);
	if (f[flags->i] == '%')
		process_percent(flags);
	if (f[flags->i] == 's')
		process_string(flags, argm);
	if (f[flags->i] == 'd' || f[flags->i] == 'i')
		process_integer(flags, argm);
	if (f[flags->i] == 'u')
		process_unsigned(flags, argm);
	if (f[flags->i] == 'x' || f[flags->i] == 'X')
	{
		if (f[flags->i] == 'x')
			capitalize = 0;
		else
			capitalize = 1;
		process_hex(flags, argm, capitalize);
	}
	if (f[flags->i] == 'p')
		process_pointer(flags, argm);
}

int		ft_printf(const char *format, ...)
{
	t_struct	flags;

	flags.i = 0;
	flags.count = 0;
	va_list	argm;
	va_start(argm, format);
	init_struct(&flags);
	while (format[flags.i])
	{
		if (format[flags.i] == '%')
		{
			init_struct(&flags);
			flags.i++;
			check_flags(format, &flags);
			check_width(format, &flags, argm);
			check_precision(format, &flags, argm);
			if (!(flags.type = format[flags.i]))
				break ;
			process_type(format, &flags, argm);
		}
		else
			ft_putchar(format[flags.i], &flags);
		flags.i++;
	}
	va_end(argm);
	return (flags.count);
}
