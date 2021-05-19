/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:02 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:03 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*next;

	if (!(stacks->stack_a) || !(stacks->stack_a->next))
		return ;
	tmp = stacks->stack_a;
	next = stacks->stack_a->next->next;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->next = tmp;
	stacks->stack_a->next->next = next;
}

void	ft_sb(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*next;

	if (!(stacks->stack_b) || !(stacks->stack_b->next))
		return ;
	tmp = stacks->stack_b;
	next = stacks->stack_b->next->next;
	stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->next = tmp;
	stacks->stack_b->next->next = next;
}

void	ft_ra(t_stack *stacks)
{
	t_num	*tmp;

	if (!(stacks->stack_a) || !(stacks->stack_a->next))
		return ;
	tmp = stacks->stack_a->next;
	ft_lstadd_back(&stacks->stack_a, stacks->stack_a);
	stacks->stack_a = tmp;
}

void	ft_rb(t_stack *stacks)
{
	t_num	*tmp;

	if (!(stacks->stack_b) || !(stacks->stack_b->next))
		return ;
	tmp = stacks->stack_b->next;
	ft_lstadd_back(&stacks->stack_b, stacks->stack_b);
	stacks->stack_b = tmp;
}

void	ft_rrb(t_stack *stacks)
{
	t_num	*tmp;

	if (!(stacks->stack_b) || !(stacks->stack_b->next))
		return ;
	tmp = stacks->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&stacks->stack_b, ft_lstnode(stacks->stack_b));
	tmp->next = NULL;
}
