/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:52 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:53 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_next_line(char **line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!line)
		return (-1);
	*line = malloc(1024 * 1024);
	if (!(*line))
		return (-1);
	while (1)
	{
		ret = read(0, &(*line)[i], 1);
		if (ret == 0)
			break ;
		if ((*line)[i] == '\n')
		{
			(*line)[i] = (0);
			return (1);
		}
		i++;
	}
	(*line)[i] = 0;
	return (ret);
}

void	ft_cmdlist(char *line, t_stack *stacks)
{
	t_cmd	*newcmd;

	if (!(stacks->head))
	{
		stacks->cmds = ft_newcmd(line);
		stacks->head = 1;
	}
	else
	{
		newcmd = ft_newcmd(line);
		ft_lstadd_backcmd(&stacks->cmds, newcmd);
	}
}

void	ft_readcmd(t_stack *stacks)
{
	int		r;
	char	*line;

	stacks->head = 0;
	line = NULL;
	r = 1;
	while (1)
	{
		r = ft_get_next_line(&line);
		if (r == 0)
			break ;
		ft_checkline(line, stacks);
		ft_cmdlist(line, stacks);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	line = NULL;
}
