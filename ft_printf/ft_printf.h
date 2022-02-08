/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:22:04 by gneri             #+#    #+#             */
/*   Updated: 2021/02/11 17:22:08 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_flags{
	
	int i;
	int minus;
	int zero;
	int width;
	int	prec;
	char type;
	int count;

} t_struct;

int		ft_printf(const char *format, ...);
void	init_struct(t_struct *flags);
void	check_flags(const char *f, t_struct *flags);
void	check_width(const char *f, t_struct *flags, va_list argm);
void	check_precision(const char *f, t_struct *flags, va_list argm);
void	process_type(const char *f, t_struct *flags, va_list argm);
void	process_char(t_struct *flags, va_list argm);
void	process_unsigned(t_struct *flags,va_list argm);
void	process_hex(t_struct *flags, va_list argm, int capitalize);
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_atoi(const char *s);
void	ft_putchar(char c, t_struct *flags);
void	ft_putstr(char *str, t_struct *flags);
void	ft_putstr_str(char *str, t_struct *flags, int len);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_utoa_base(unsigned long int n, int base);
char	*ft_toupper(char *str);
int		num_lenght(long int n, int base);
void	print_space_pointer(t_struct *flags);
void	print_pointer_minus(t_struct *flags, char *ptr, int len);
void	print_pointer(t_struct *flags, char *ptr, int len);
void	check_num0_pre0(t_struct *flags);
void	print_zero(t_struct *flags, char *num_str);
void	print_zero_space(t_struct *flags, int len);
void	print_int_minus(t_struct *flags, char *num_str, int len);
void	print_int(t_struct *flags, int num, char *num_str, int len);
char	*ft_strdup(char *s1);
void	print_space(t_struct *flags, int len);
int		value_len_str(t_struct *flags, char *arg, int len);
int		value_len_int(t_struct *flags, int num, char *num_str);
void	print_uns_hex(t_struct *flags, char *num_str, int len);
void	process_pointer(t_struct *flags, va_list argm);
void	process_string(t_struct *flags, va_list argm);
void	process_integer(t_struct *flags , va_list argm);
void	process_percent(t_struct *flags);

#endif
