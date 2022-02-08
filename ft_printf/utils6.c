/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:16:18 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:16:20 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_hex(t_struct *flags, va_list argm, int capitalize)
{
	unsigned int	num;
	char			*num_str;
	int				len;

	num = va_arg(argm, unsigned int);
	if (flags->prec == 0 && num == 0) 
	{
		while (flags->width--)
			ft_putchar(' ', flags);
		return ;
	}
	num_str = ft_utoa_base(num, 16);
	if (capitalize == 1)
		ft_toupper(num_str);
	if (flags->prec > ft_strlen(num_str))
		len = flags->prec; 
	else
		len = ft_strlen(num_str);
	print_uns_hex(flags, num_str, len);
}

void	print_space_pointer(t_struct *flags)
{
	while (flags->width && (flags->width - 2) > 0)
	{
		ft_putchar(' ', flags);
		flags->width--;
	}
}

void	print_pointer_minus(t_struct *flags, char *ptr, int len)
{
	if (flags->prec >= 0 && flags->prec > ft_strlen(ptr))
	{
		print_zero(flags, ptr);
		ft_putstr("0x", flags);
		ft_putstr(ptr, flags);
	}
	else
	{
		ft_putstr("0x", flags);
		ft_putstr(ptr, flags);
	}
	print_space(flags, len);
}

void	print_pointer(t_struct *flags, char *ptr, int len)
{
	print_zero_space(flags, len); 
	if (flags->prec >= 0 && flags->prec > ft_strlen(ptr))
	{
		ft_putstr("0x", flags);
		print_zero(flags, ptr);
		ft_putstr(ptr, flags);
	}
	else
	{
		ft_putstr("0x", flags);
		ft_putstr(ptr, flags);
	}
}

void	check_num0_pre0(t_struct *flags)
{
	if (flags->minus == 1)
	{
		ft_putstr("0x", flags);
		print_space_pointer(flags);
	}
	else
	{
		print_space_pointer(flags);
		ft_putstr("0x", flags);
	}
}
