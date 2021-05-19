/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:26 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:28 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	if (argc < 2)
		exit(0);
	if (!argv[1][0])
	{
		ft_putstr("Error\n");
		exit(0);
	}
	ft_parsing(argc, argv, &stacks);
	ft_check_duplicate(&stacks);
	ft_rightmove(&stacks);
	ft_clean(&stacks.stack_a);
	ft_clean(&stacks.stack_b);
	ft_clean_checker(&stacks.clone);
}
