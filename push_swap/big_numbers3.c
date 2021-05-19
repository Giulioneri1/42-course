/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:03:28 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:03:30 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_to_top_a2(t_cmd **cmd, int len)
{
	t_cmd	*newcmd;

	while (len-- > 0)
	{
		if (!*cmd)
			*cmd = ft_newcmd("rra");
		else
		{
			newcmd = ft_newcmd("rra");
			ft_lstadd_backcmd(cmd, newcmd);
		}
	}
}

void	ft_to_top_a(t_num *stack, t_num *node, t_cmd **cmd)
{
	t_cmd	*newcmd;
	int		len;
	int		lstsize;
	int		m;

	if (ft_lstsize(stack) % 2 == 0)
		m = ft_lstsize(stack) / 2;
	else
		m = (ft_lstsize(stack) / 2) + 1;
	len = ft_lstsize(node);
	if (len >= m)
	{
		while (len++ < ft_lstsize(stack))
		{
			if (!*cmd)
				*cmd = ft_newcmd("ra");
			else
			{
				newcmd = ft_newcmd("ra");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
	}
	else
		ft_to_top_a2(cmd, len);
}

void	ft_to_top_b2(t_cmd **cmd, int len)
{
	t_cmd	*newcmd;

	while (len-- > 0)
	{
		if (!*cmd)
			*cmd = ft_newcmd("rrb");
		else
		{
			newcmd = ft_newcmd("rrb");
			ft_lstadd_backcmd(cmd, newcmd);
		}
	}
}

void	ft_to_top_b(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd)
{
	t_cmd	*newcmd;
	int		len;
	int		m;

	if (ft_lstsize(stack) % 2 == 0)
		m = ft_lstsize(stack) / 2;
	else
		m = (ft_lstsize(stack) / 2) + 1;
	len = ft_lstsize(node);
	if (len >= m)
	{
		while (len++ < ft_lstsize(stack))
		{
			if (!*cmd)
				*cmd = ft_newcmd("rb");
			else
			{
				newcmd = ft_newcmd("rb");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
	}
	else if (len < m)
		ft_to_top_b2(cmd, len);
}

void	ft_pa_node(t_cmd **node)
{
	t_cmd	*newcmd;

	if (!*node)
		(*node) = ft_newcmd("pa");
	else
	{
		newcmd = ft_newcmd("pa");
		ft_lstadd_backcmd(&(*node), newcmd);
	}
}
