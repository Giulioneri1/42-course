/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:05:30 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:05:31 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_num	*ft_newnode(int num)
{
	t_num	*new;

	new = (t_num *)malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->number = num;
	new->next = NULL;
	return (new);
}

t_num	*ft_lstnode(t_num *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_back(t_num **node, t_num *new)
{
	if (!*node)
		*node = new;
	else
		ft_lstnode(*node)->next = new;
	new->next = NULL;
}

void	ft_lstadd_front(t_num **lst, t_num *new)
{
	if (!*lst)
		new->next = 0;
	else
		new->next = *lst;
	*lst = new;
}

t_cmd	*ft_newcmd(char *str)
{
	t_cmd	*new;
	int		len;

	len = ft_strlen(str);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = malloc(sizeof(char) * (len + 1));
	ft_memcpy(new->cmd, str, len + 1);
	new->cmd[len] = '\0';
	new->next = NULL;
	return (new);
}
