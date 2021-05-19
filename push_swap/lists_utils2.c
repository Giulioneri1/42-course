/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:38 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:39 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_cmd	*ft_lstnodecmd(t_cmd *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_backcmd(t_cmd **node, t_cmd *new)
{
	if (!*node)
		*node = new;
	else
		ft_lstnodecmd(*node)->next = new;
	new->next = NULL;
}

int	ft_lstsize(t_num *lst)
{
	int	x;

	x = 0;
	while (lst)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

int	ft_lstsizecmd(t_cmd *lst)
{
	int	x;

	x = 0;
	while (lst)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

int	ft_sorted(t_num *stack)
{
	int		num;
	t_num	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		num = tmp->number;
		if (num > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
