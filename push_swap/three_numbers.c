/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:59 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:07:00 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_three_numbers2(t_stack *stacks, t_num *tmp, t_num *head)
{
	if (tmp->number > head->number && tmp->number > tmp->next->number
		&& head->number < tmp->next->number)
	{
		ft_rra(stacks);
		ft_putstr("rra\n");
		ft_sa(stacks);
		ft_putstr("sa\n");
		return ;
	}
	else if (tmp->number > head->number && tmp->number > tmp->next->number
		&& head->number > tmp->next->number)
	{
		ft_rra(stacks);
		ft_putstr("rra\n");
		return ;
	}
	else if (tmp->number < head->number && tmp->number > tmp->next->number)
	{
		ft_sa(stacks);
		ft_putstr("sa\n");
		ft_rra(stacks);
		ft_putstr("rra\n");
		return ;
	}
}

void	ft_three_numbers(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*head;

	head = stacks->stack_a;
	tmp = stacks->stack_a->next;
	if (tmp->number < head->number && tmp->number < tmp->next->number
		&& head->number < tmp->next->number)
	{
		ft_sa(stacks);
		ft_putstr("sa\n");
		return ;
	}
	else if (tmp->number < head->number && tmp->number < tmp->next->number
		&& head->number > tmp->next->number)
	{
		ft_ra(stacks);
		ft_putstr("ra\n");
		return ;
	}
	else
		ft_three_numbers2(stacks, tmp, head);
}
