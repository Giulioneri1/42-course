/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:34 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:36 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_rightmove(t_stack *stacks)
{
	t_num	*tmp;

	stacks->clone = NULL;
	ft_initcmd(stacks);
	tmp = stacks->stack_a;
	if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) == 2))
	{
		ft_sa(stacks);
		ft_putstr("sa\n");
	}
	if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) == 3))
		ft_three_numbers(stacks);
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) > 3
			&& (ft_lstsize(stacks->stack_a) <= 5)))
		ft_five_numbers(stacks);
	else if (!ft_sorted(stacks->stack_a) && (ft_lstsize(stacks->stack_a) > 5))
	{
		ft_subsequence(stacks);
		ft_algorithm(stacks);
	}
}

void	ft_parse_numbers(t_stack *stacks, char **numbers)
{
	int		j;
	int		num;
	t_num	*newnode;

	j = 0;
	while (numbers[j])
	{
		num = ft_atoi(numbers[j], &stacks->stack_a);
		if (!(stacks->head))
		{
			stacks->stack_a = ft_newnode(num);
			stacks->head = 1;
		}
		else
		{
			newnode = ft_newnode(num);
			ft_lstadd_back(&stacks->stack_a, newnode);
		}
		free(numbers[j]);
		j++;
	}
}

void	ft_parsing(int argc, char **argv, t_stack *stacks)
{
	int		i;
	char	**numbers;

	stacks->head = 0;
	i = 1;
	while (i < argc)
	{
		ft_checkstr(argv[i], stacks);
		numbers = ft_split(argv[i], ' ');
		ft_parse_numbers(stacks, numbers);
		i++;
		free(numbers);
	}
}

void	ft_check_duplicate(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*tmp2;
	int		num;
	int		num2;

	tmp = stacks->stack_a;
	while (tmp)
	{
		num = tmp->number;
		tmp2 = tmp;
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
			num2 = tmp2->number;
			if (num == num2)
				ft_error(&stacks->stack_a);
		}
		tmp = tmp->next;
	}
}
