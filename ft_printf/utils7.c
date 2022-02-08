/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:18:35 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:18:40 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_pointer(t_struct *flags, va_list argm)
{
	char				*ptr;
	unsigned long int	num;
	int					len;
	
	num = va_arg(argm, unsigned long int);
	if (num == 0 && flags->prec == 0)
	{
		check_num0_pre0(flags);
		return ;
	}
	ptr = ft_utoa_base(num, 16);
	if (flags->prec > ft_strlen(ptr))
		len = flags->prec + 2;
	else
		len = ft_strlen(ptr) + 2;
	if (flags->minus == 1)
		print_pointer_minus(flags, ptr, len);
	else 
		print_pointer(flags, ptr, len);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}