/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:06:10 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:06:11 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_samove(t_stack *stacks)
{
	ft_sa(stacks);
	ft_putstr("sa\n");
}

void	ft_sbmove(t_stack *stacks)
{
	ft_sb(stacks);
	ft_putstr("sb\n");
}

void	ft_rramove(t_stack *stacks)
{
	ft_rra(stacks);
	ft_putstr("rra\n");
}

void	ft_rrrmove(t_stack *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	ft_putstr("rrr\n");
}

void	ft_rrbmove(t_stack *stacks)
{
	ft_rrb(stacks);
	ft_putstr("rrb\n");
}
