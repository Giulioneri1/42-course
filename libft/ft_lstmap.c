/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:15:15 by gneri             #+#    #+#             */
/*   Updated: 2021/01/21 18:15:17 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	list = 0;
	if (lst)
	{
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
			lst = lst->next;
		}
	}
	return (list);
}
