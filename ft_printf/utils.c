/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:16:54 by gneri             #+#    #+#             */
/*   Updated: 2021/02/24 17:17:01 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *flags)
{
	write(1, &c, 1);
	flags->count++;
}

void	ft_putstr_str(char *str, t_struct *flags, int len)
{
	int i;

	i = 0;
	if (flags->prec >= 0 && flags->type == 's')
	{
		while (i != len)
		{
			ft_putchar(str[i], &(*flags));
			i++;
		}
	}
	else
	{ 
		while (str[i])
		{
			ft_putchar(str[i], &(*flags));
			i++;
		}
	}
}

void	ft_putstr(char *str, t_struct *flags)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], &(*flags));
		i++;
	}
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
