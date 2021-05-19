/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:00 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:01 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_initcmd(t_stack *stacks)
{
	t_num	*head_a;
	t_num	*head_b;

	head_a = stacks->stack_a;
	head_b = stacks->stack_b;
	while (head_a)
	{
		head_a->cmd = NULL;
		head_a = head_a->next;
	}
	while (head_b)
	{
		head_b->cmd = NULL;
		head_b = head_b->next;
	}
}

void	ft_initflag(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->stack_a;
	while (tmp)
	{
		tmp->count = 0;
		tmp->flag = 1;
		tmp->sub_c = '0';
		tmp->move = NULL;
		tmp = tmp->next;
	}
	tmp = stacks->clone;
	while (tmp)
	{
		tmp->count = 0;
		tmp->flag = 1;
		tmp->sub_c = '0';
		tmp->move = NULL;
		tmp = tmp->next;
	}
}
