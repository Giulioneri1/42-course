/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:56:55 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 17:19:59 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
int	ft_lstsize(t_num *lst)
{
	int x;

	x = 0;
	while (lst)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

int	ft_lstsizecmd(t_cmd *lst)
{
	int x;

	x = 0;
	while (lst)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

int ft_sorted(t_num *stack)
{
	int num;
	t_num	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		num = tmp->number;
		if (num > tmp->next->number)
			return 0;
		tmp = tmp->next;
	}
	return (1);
}


void ft_rightmove(t_stack *stacks)
{
	t_num *tmp;

	stacks->clone = NULL;
	ft_initcmd(stacks);
	tmp = stacks->stack_a;
	if(!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) == 2))
	{
		ft_sa(stacks);
		ft_putstr("sa\n");
	}
	if(!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) == 3))
		ft_threemoves(stacks);
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) > 3 && (ft_lstsize(stacks->stack_a) <= 5)))
		ft_fivemoves(stacks);
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) > 5 && (ft_lstsize(stacks->stack_a) <= 100)))
		{
			stacks->chunks = 3;
			ft_hundred(stacks);
		}
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) > 100))
		{
			stacks->chunks = 5;
			ft_hundred(stacks);
		}
}