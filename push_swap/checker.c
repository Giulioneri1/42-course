/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:49:02 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 17:27:36 by fulloa-s         ###   ########.fr       */
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
	ft_readcmd(&stacks);
	ft_moves(&stacks);
	ft_lastcheck(&stacks);
	ft_clean_checker(&stacks.stack_a);
	ft_clean_checker(&stacks.stack_b);
	ft_cleancmd(&stacks.cmds);
 }
