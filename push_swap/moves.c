/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:19:31 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 16:50:00 by fulloa-s         ###   ########.fr       */
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

void	ft_ra_clone(t_stack *stacks)
{
	t_num	*tmp;
	
	if (!(stacks->clone) || !(stacks->clone->next))
		return ;
	tmp = stacks->clone->next;
	ft_lstadd_back(&stacks->clone, stacks->clone);
	stacks->clone = tmp;
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

void	ft_rra(t_stack *stacks)
{
	t_num	*tmp;

	if (!(stacks->stack_a) || !(stacks->stack_a->next))
		return ;
	tmp = stacks->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&stacks->stack_a, ft_lstnode(stacks->stack_a));
	tmp->next = NULL;
}

void	ft_pa(t_stack *stacks)
{
	t_num	*tmp;

	if (!stacks->stack_b)
		return ;
	tmp = stacks->stack_b->next;
	ft_lstadd_front(&stacks->stack_a, stacks->stack_b);
	stacks->stack_b = tmp;
}

void	ft_pb(t_stack *stacks)
{
	t_num	*tmp;

	if (!stacks->stack_a)
		return ;
	tmp = stacks->stack_a->next;
	ft_lstadd_front(&stacks->stack_b, stacks->stack_a);
	stacks->stack_a = tmp;
}

void	ft_moves(t_stack *stacks)
{
	t_cmd	*tmp;

	tmp = stacks->cmds;
	while (tmp)
	{
		if ((ft_strncmp(tmp->cmd, "sa", 2)) == 0)
			ft_sa(stacks);
		else if ((ft_strncmp(tmp->cmd, "sb", 2)) == 0)
			ft_sb(stacks);
		else if ((ft_strncmp(tmp->cmd, "ss", 2)) == 0)
		{
			ft_sa(stacks);
			ft_sb(stacks);
		}
		else if ((ft_strncmp(tmp->cmd, "rra", 3)) == 0)
			ft_rra(stacks);
		else if ((ft_strncmp(tmp->cmd, "rrb", 3)) == 0)
			ft_rrb(stacks);
		else if ((ft_strncmp(tmp->cmd, "rrr", 3)) == 0)
		{
			ft_rra(stacks);
			ft_rrb(stacks);
		}
		else if ((ft_strncmp(tmp->cmd, "ra", 2)) == 0)
			ft_ra(stacks);
		else if ((ft_strncmp(tmp->cmd, "rb", 2)) == 0)
			ft_rb(stacks);
		else if ((ft_strncmp(tmp->cmd, "rr", 2)) == 0)
		{
			ft_ra(stacks);
			ft_rb(stacks);
		}
		else if ((ft_strncmp(tmp->cmd, "pa", 2)) == 0)
			ft_pa(stacks);
		else if ((ft_strncmp(tmp->cmd, "pb", 2)) == 0)
			ft_pb(stacks);
		tmp = tmp->next;
	}
}
