/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:52 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:56 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_moves2(t_stack *stacks, t_cmd *tmp)
{
	if ((ft_strncmp(tmp->cmd, "rrr", 3)) == 0)
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
		else
			ft_moves2(stacks, tmp);
		tmp = tmp->next;
	}
}
