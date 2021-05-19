/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:38 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:40 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_five_numbers(t_stack *stacks)
{
	t_num	*head_a;
	t_num	*head_b;
	int		i;

	i = 0;
	while (i++ < 2)
		ft_pbmove(stacks);
	if (ft_lstsize(stacks->stack_a) == 3)
		ft_three_numbers(stacks);
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
			ft_five_numbers2(stacks, head_a, head_b);
	}
}

void	ft_five_numbers2(t_stack *stacks, t_num	*head_a, t_num	*head_b)
{
	int	m;

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
		ft_five_numbers3(stacks, head_a, head_b, m);
		m++;
		head_a = head_a->next;
	}
}

void	ft_five_numbers3(t_stack *stacks, t_num	*head_a, t_num	*head_b, int m)
{
	if (head_b->number > head_a->number
		&& head_b->number < head_a->next->number
		&& m == 2 && (ft_lstsize(stacks->stack_a) == 4))
	{
		ft_ramove(stacks);
		ft_pamove(stacks);
		ft_samove(stacks);
		ft_rramove(stacks);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
