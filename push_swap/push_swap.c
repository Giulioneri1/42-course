/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:55:56 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 17:33:17 by fulloa-s         ###   ########.fr       */
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
	ft_parsing(argc, argv, &stacks);
	ft_check_duplicate(&stacks);
	ft_rightmove(&stacks);
	ft_clean(&stacks.stack_a);
	ft_clean(&stacks.stack_b);
	ft_clean(&stacks.clone);
}