/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:52:54 by gneri             #+#    #+#             */
/*   Updated: 2021/02/01 15:58:08 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_realloc(char **line)
{
	char	*tmp;
	int		k;
	int		i;

	k = 0;
	i = (*line) ? ft_strlen(*line) : 0;
	if (!(tmp = malloc(sizeof(char) * (i + BUFFER_SIZE + 1))))
		return (NULL);
	if (*line)
	{
		while ((*line)[k])
		{
			tmp[k] = (*line)[k];
			k++;
		}
		free(*line);
	}
	tmp[k] = '\0';
	return (tmp);
}

char	*ft_realloc_finale(char **line)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	i = (*line) ? ft_strlen(*line) : 0;
	if (!(tmp = malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (*line)
	{
		while ((*line)[k])
		{
			tmp[k] = (*line)[k];
			k++;
		}
		free(*line);
	}
	tmp[k] = 0;
	return (tmp);
}
