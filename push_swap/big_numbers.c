/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:03:14 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:03:16 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exec_moves(t_stack *stacks, t_cmd *min)
{
	while (min)
	{
		if (!ft_strncmp(min->cmd, "ra", 2))
			ft_ramove(stacks);
		else if (!ft_strncmp(min->cmd, "rb", 2))
			ft_rbmove(stacks);
		else if (!ft_strncmp(min->cmd, "rra", 3))
			ft_rramove(stacks);
		else if (!ft_strncmp(min->cmd, "rrb", 3))
			ft_rrbmove(stacks);
		else if (!ft_strncmp(min->cmd, "rrr", 3))
			ft_rrrmove(stacks);
		else if (!ft_strncmp(min->cmd, "pa", 2))
			ft_pamove(stacks);
		else if (!ft_strncmp(min->cmd, "rr", 2))
			ft_rrmove(stacks);
		min = min->next;
	}
}

void	ft_print_moves(t_stack *stacks)
{
	t_num	*head_b;
	t_num	*min;
	t_cmd	*tmp;

	head_b = stacks->stack_b;
	min = head_b;
	while (head_b)
	{
		if (head_b->count < min->count)
			min = head_b;
		if (head_b->count < min->count && ft_strncmp(head_b->cmd->cmd, "rr", 2))
			min = head_b;
		head_b = head_b->next;
	}
	tmp = min->cmd;
	ft_exec_moves(stacks, tmp);
}

void	ft_sort_a(t_stack *stacks)
{
	t_num	*min;
	t_num	*tmp;
	int		m;
	int		len;

	tmp = stacks->stack_a;
	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
	else
		m = (ft_lstsize(tmp) / 2) + 1;
	min = ft_findmin(stacks->stack_a);
	len = ft_lstsize(min);
	while (!ft_sorted(stacks->stack_a))
	{
		if (len >= m)
			ft_ramove(stacks);
		else
			ft_rramove(stacks);
	}
}

void	ft_exec_algorithm(t_stack *stacks, t_num *head_b)
{
	t_cmd	*cmd_b;
	t_cmd	*cmd_a;

	while (head_b)
	{
		cmd_b = NULL;
		cmd_a = NULL;
		head_b->cmd = NULL;
		ft_to_top_b(stacks, stacks->stack_b, head_b, &cmd_b);
		ft_pos_in_a(stacks, stacks->stack_a, head_b, &cmd_a);
		ft_realmove(&head_b->cmd, cmd_b, cmd_a);
		head_b->count = head_b->cmd->count;
		ft_cleancmd(&cmd_b);
		ft_cleancmd(&cmd_a);
		head_b = head_b->next;
	}
}

void	ft_algorithm(t_stack *stacks)
{
	t_num	*head_b;

	ft_initcmd(stacks);
	while (stacks->stack_b)
	{
		head_b = stacks->stack_b;
		stacks->min_a = ft_findmin(stacks->stack_a);
		stacks->max_a = ft_findmax(stacks->stack_a);
		ft_exec_algorithm(stacks, head_b);
		ft_print_moves(stacks);
		ft_clean_algorithm(stacks);
	}
	ft_sort_a(stacks);
}
