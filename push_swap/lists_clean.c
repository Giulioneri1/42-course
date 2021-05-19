/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:21 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:22 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_clean(t_num **stack)
{
	t_num	*ptr;
	t_cmd	*ptr_2;

	while (*stack)
	{
		ptr = (*stack)->next;
		(*stack)->number = 0;
		if ((*stack)->cmd)
		{
			while ((*stack)->cmd)
			{
				if ((*stack)->cmd->next)
					ptr_2 = (*stack)->cmd->next;
				free((*stack)->cmd->cmd);
				free((*stack)->cmd);
				(*stack)->cmd = ptr_2;
			}
		}
		free(*stack);
		(*stack) = ptr;
	}	
}

void	ft_cleancmd(t_cmd **cmds)
{
	t_cmd	*ptr;

	while ((*cmds))
	{
		ptr = (*cmds)->next;
		ft_bzero((*cmds)->cmd, ft_strlen((*cmds)->cmd));
		free((*cmds)->cmd);
		free(*cmds);
		(*cmds) = ptr;
	}	
}

void	ft_clean_checker(t_num **stack)
{
	t_num	*ptr;
	t_cmd	*ptr_2;

	while (*stack)
	{
		ptr = (*stack)->next;
		(*stack)->number = 0;
		free(*stack);
		(*stack) = ptr;
	}	
}

void	ft_clean_algorithm(t_stack *stacks)
{
	t_num	*head_b;
	t_num	*head_a;

	head_a = stacks->stack_a;
	head_b = stacks->stack_b;
	while (head_a)
	{
		ft_cleancmd(&head_a->cmd);
		head_a = head_a->next;
	}
	while (head_b)
	{
		ft_cleancmd(&head_b->cmd);
		head_b = head_b->next;
	}
}
