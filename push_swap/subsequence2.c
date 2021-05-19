/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:51 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:52 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_findsub(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*tmp2;

	while (stacks->max_flag)
	{
		tmp = stacks->clone;
		while (tmp && tmp->sub_c == '0')
		{
			if (tmp->flag == stacks->max_flag)
				tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->sub_c = '*';
		stacks->max_flag--;
	}
	ft_findrealsub(stacks);
}

void	ft_findrealsub(t_stack *stacks)
{
	t_num	*tmp_a;
	t_num	*tmp_c;

	tmp_c = stacks->clone;
	while (tmp_c)
	{
		tmp_a = stacks->stack_a;
		while (tmp_a)
		{
			if (tmp_c->sub_c == '*' && tmp_c->number == tmp_a->number)
			{
				tmp_a->sub_c = '*';
				break ;
			}
			tmp_a = tmp_a->next;
		}
		tmp_c = tmp_c->next;
	}
}

void	ft_ra_clone(t_stack *stacks)
{
	t_num	*tmp;

	if (!(stacks->clone) || !(stacks->clone->next))
		return ;
	tmp = stacks->clone->next;
	ft_lstadd_back(&stacks->clone, stacks->clone);
	stacks->clone = tmp;
}
