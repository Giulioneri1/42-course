/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:44 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:45 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ordersub(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->stack_a;
	while (tmp)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
	tmp = stacks->stack_a;
	while (tmp && tmp->flag != 1)
	{	
		if (tmp->sub_c == '*')
		{
			ft_ramove(stacks);
			tmp->flag = 1;
		}
		else
			ft_pbmove(stacks);
		tmp = stacks->stack_a;
	}
}

void	ft_sortclone(t_stack *stacks)
{
	t_num	*min;
	t_num	*tmp;

	min = ft_findmin(stacks->clone);
	tmp = stacks->clone;
	while (tmp != min)
	{
		ft_ra_clone(stacks);
		tmp = stacks->clone;
	}
}

void	ft_clone(t_stack *stacks)
{
	t_num	*tmp_a;
	t_num	*newnode;

	stacks->clone = NULL;
	tmp_a = stacks->stack_a;
	while (tmp_a)
	{
		if (!stacks->clone)
			stacks->clone = ft_newnode(tmp_a->number);
		else
		{
			newnode = ft_newnode(tmp_a->number);
			ft_lstadd_back(&stacks->clone, newnode);
		}
		tmp_a = tmp_a->next;
	}
	ft_sortclone(stacks);
}

void	ft_findflag(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->clone;
	stacks->max_flag = tmp->flag;
	while (tmp)
	{
		if (tmp->flag > stacks->max_flag)
			stacks->max_flag = tmp->flag;
		tmp = tmp->next;
	}
	ft_findsub(stacks);
}

void	ft_subsequence(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*tmp2;

	ft_clone(stacks);
	ft_initflag(stacks);
	tmp = stacks->clone;
	while (tmp->next)
	{
		tmp2 = tmp;
		while (tmp2)
		{
			if ((tmp->number < tmp2->number) && (tmp->flag == tmp2->flag))
				tmp2->flag++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	ft_findflag(stacks);
	ft_ordersub(stacks);
}
