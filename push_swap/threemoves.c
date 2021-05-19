/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threemoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:40:37 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 11:56:12 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_threemoves(t_stack *stacks)
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

void	ft_pbmove(t_stack *stacks)
{
	ft_pb(stacks);
	ft_putstr("pb\n");
}

void	ft_pamove(t_stack *stacks)
{
	ft_pa(stacks);
	ft_putstr("pa\n");
}

void	ft_ramove(t_stack *stacks)
{
	ft_ra(stacks);
	ft_putstr("ra\n");
}

void	ft_rbmove(t_stack *stacks)
{
	ft_rb(stacks);
	ft_putstr("rb\n");
}

void	ft_rrmove(t_stack *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	ft_putstr("rr\n");
}

void	ft_samove(t_stack *stacks)
{
	ft_sa(stacks);
	ft_putstr("sa\n");
}

void	ft_sbmove(t_stack *stacks)
{
	ft_sb(stacks);
	ft_putstr("sb\n");
}

void	ft_rramove(t_stack *stacks)
{
	ft_rra(stacks);
	ft_putstr("rra\n");
}

void	ft_rrrmove(t_stack *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	ft_putstr("rrr\n");
}

void	ft_rrbmove(t_stack *stacks)
{
	ft_rrb(stacks);
	ft_putstr("rrb\n");
}

void	ft_fivemoves(t_stack *stacks)
{
	t_num	*head_a;
	t_num	*head_b;
	int		i;
	int		m;

	i = 0;
	while (i++ < 2)
		ft_pbmove(stacks);
	if (ft_lstsize(stacks->stack_a) == 3)
		ft_threemoves(stacks);
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) == 2))
		ft_samove(stacks);
	while (i-- > 1)
	{
		head_a = stacks->stack_a;
		head_b = stacks->stack_b;
		if (head_b->number < head_a->number)
			ft_pamove(stacks);
		else if (head_b->number > ft_lstnode(head_a)->number)
		{
			ft_pamove(stacks);
			ft_ramove(stacks);
		}
		else
		{
			m = 1;
			while (head_a->next)
			{
				if (head_b->number > head_a->number
					&& head_b->number < head_a->next->number && m == 1)
				{
					ft_pamove(stacks);
					ft_samove(stacks);
				}
				else if (head_b->number > head_a->number
					&& head_b->number < head_a->next->number
					&& ((m == 2 && (ft_lstsize(stacks->stack_a) == 3))
						|| m == 3))
				{
					ft_rramove(stacks);
					ft_pamove(stacks);
					ft_ramove(stacks);
					ft_ramove(stacks);
				}
				else if (head_b->number > head_a->number
					&& head_b->number < head_a->next->number
					&& m == 2 && (ft_lstsize(stacks->stack_a) == 4))
				{
					ft_ramove(stacks);
					ft_pamove(stacks);
					ft_samove(stacks);
					ft_rramove(stacks);
				}
				m++;
				head_a = head_a->next;
			}
		}
	}
}
