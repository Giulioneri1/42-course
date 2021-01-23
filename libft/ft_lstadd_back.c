/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:22:44 by gneri             #+#    #+#             */
/*   Updated: 2021/01/20 15:22:46 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		tmp = *lst;
		if (tmp == NULL)
			*lst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			if (tmp->next == NULL)
				tmp->next = new;
		}
	}
}
