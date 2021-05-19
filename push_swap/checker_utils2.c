/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:22 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:24 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	ft_checkline(char *line, t_stack *stacks)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 2 && ft_strlen(line) != 3)
		ft_error(&stacks->stack_a);
	if (ft_strlen(line) == 2 && (ft_strncmp(line, "sa", 2) != 0 && \
	ft_strncmp(line, "sb", 2) != 0 && ft_strncmp(line, "ss", 2) != 0 && \
	ft_strncmp(line, "pa", 2) != 0 && ft_strncmp(line, "pb", 2) != 0 && \
	ft_strncmp(line, "ra", 2) != 0 && ft_strncmp(line, "rb", 2) != 0 && \
	ft_strncmp(line, "rr", 2) != 0))
		ft_error(&stacks->stack_a);
	if (ft_strlen(line) == 3 && (ft_strncmp(line, "rra", 3) != 0 && \
	ft_strncmp(line, "rrb", 3) != 0 && ft_strncmp(line, "rrr", 3) != 0))
		ft_error(&stacks->stack_a);
}

void	ft_error(t_num **stack)
{
	ft_clean_checker(stack);
	write(1, "Error\n", 6);
	exit(0);
}
