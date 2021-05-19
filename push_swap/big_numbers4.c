/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:03:37 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:03:39 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_choice(t_stack *stacks, t_num *stack, t_num *num)
{
	t_num	*tmp;
	int		m;
	int		count_f;

	count_f = 0;
	tmp = stack;
	if (ft_lstsize(stack) % 2 == 0)
		m = ft_lstsize(stack) / 2;
	else
		m = (ft_lstsize(stack) / 2) + 1;
	if (num)
	{
		count_f = ft_count(stack, num, m);
		if (ft_lstsize(num) >= m)
			while (count_f-- > 0)
				ft_ramove(stacks);
		else
			while (count_f-- > 0)
				ft_rramove(stacks);
	}
}

t_num	*ft_findmin(t_num *stack)
{
	t_num	*min;
	t_num	*head_a;

	head_a = stack;
	min = head_a;
	while (head_a)
	{
		if (min->number > head_a->number)
			min = head_a;
		head_a = head_a->next;
	}
	return (min);
}

t_num	*ft_findmax(t_num *stack)
{
	t_num	*max;
	t_num	*head_a;

	head_a = stack;
	max = head_a;
	while (head_a)
	{
		if (max->number < head_a->number)
			max = head_a;
		head_a = head_a->next;
	}
	return (max);
}

int	ft_count2(t_num *stack, t_num *num, int m, int count)
{
	int	len;

	len = ft_lstsize(stack);
	num->move = "rra";
	while (len-- > 0)
		count++;
	return (count);
}

int	ft_count(t_num *stack, t_num *num, int m)
{
	t_num	*tmp;
	int		len;
	int		count;

	count = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp == num)
		{
			len = ft_lstsize(tmp);
			if (len >= m)
			{
				num->move = "ra";
				while (len++ < ft_lstsize(stack))
					count++;
			}
			else
				count = ft_count2(tmp, num, m, count);
		}
		tmp = tmp->next;
	}
	return (count);
}
