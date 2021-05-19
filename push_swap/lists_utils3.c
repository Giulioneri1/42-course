/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:45 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:46 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_cmds_list(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a)
{
	t_cmd	*newcmd;

	while (cmd_b)
	{
		if (!*node)
			(*node) = ft_newcmd(cmd_b->cmd);
		else
		{
			newcmd = ft_newcmd(cmd_b->cmd);
			ft_lstadd_backcmd(&(*node), newcmd);
		}
		cmd_b = cmd_b->next;
	}
	while (cmd_a)
	{
		if (!*node)
			(*node) = ft_newcmd(cmd_a->cmd);
		else
		{
			newcmd = ft_newcmd(cmd_a->cmd);
			ft_lstadd_backcmd(&(*node), newcmd);
		}
		cmd_a = cmd_a->next;
	}
}

void	ft_moves_list(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a)
{
	t_cmd	*newcmd;

	if (!*node)
	{
		(*node) = ft_newcmd(cmd_b->cmd);
		newcmd = ft_newcmd(cmd_a->cmd);
		ft_lstadd_backcmd(&(*node), newcmd);
	}
	else
	{
		newcmd = ft_newcmd(cmd_b->cmd);
		ft_lstadd_backcmd(node, newcmd);
		newcmd = ft_newcmd(cmd_a->cmd);
		ft_lstadd_backcmd(&(*node), newcmd);
	}
}
