/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:26 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:00:34 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_realmove(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a)
{
	t_cmd	*newcmd;

	while (cmd_b && cmd_a)
	{
		if (!ft_find_doubles(node, cmd_b, cmd_a))
			ft_moves_list(node, cmd_b, cmd_a);
		cmd_b = cmd_b->next;
		cmd_a = cmd_a->next;
	}
	ft_cmds_list(node, cmd_b, cmd_a);
	ft_pa_node(node);
	(*node)->count = ft_lstsizecmd((*node));
}

int	ft_find_doubles(t_cmd **node, t_cmd *tmp_b, t_cmd *tmp_a)
{
	t_cmd	*newcmd;

	if (!ft_strncmp(tmp_a->cmd, "ra", 2)
		&& !ft_strncmp(tmp_b->cmd, "rb", 2))
	{
		ft_rr_node(node);
		return (1);
	}
	else if (!ft_strncmp(tmp_a->cmd, "rra", 3)
		&& !ft_strncmp(tmp_b->cmd, "rrb", 3))
	{
		ft_rrr_node(node);
		return (1);
	}
	return (0);
}

void	ft_rr_node(t_cmd **node)
{
	t_cmd	*newcmd;

	if (!*node)
		(*node) = ft_newcmd("rr");
	else
	{
		newcmd = ft_newcmd("rr");
		ft_lstadd_backcmd(&(*node), newcmd);
	}
}

void	ft_pos_in_a(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd)
{
	int		m;
	t_num	*tmp;
	t_cmd	*newcmd;

	tmp = stack;
	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
	else
		m = (ft_lstsize(tmp) / 2) + 1;
	if (node->number < stacks->min_a->number)
		ft_to_top_a(tmp, stacks->min_a, cmd);
	else if (node->number > stacks->max_a->number)
		ft_to_top_a(tmp, stacks->min_a, cmd);
	else if (node->number < tmp->number
		&& node->number > ft_lstnode(tmp)->number)
		return ;
	else
	{
		while (tmp->next)
		{
			if (node->number > tmp->number && node->number < tmp->next->number)
				ft_to_top_a(stack, tmp->next, cmd);
			tmp = tmp->next;
		}
	}
}

void	ft_rrr_node(t_cmd **node)
{
	t_cmd	*newcmd;

	if (!*node)
		(*node) = ft_newcmd("rrr");
	else
	{
		newcmd = ft_newcmd("rrr");
		ft_lstadd_backcmd(&(*node), newcmd);
	}
}
