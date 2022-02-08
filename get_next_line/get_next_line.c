/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:51:15 by gneri             #+#    #+#             */
/*   Updated: 2021/02/03 16:59:44 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line(char **line, char *buff)
{
	int		j;
	int		k;
	int		len;

	j = 0;
	k = 0;
	*line = ft_realloc(line);
	len = (*line) ? ft_strlen(*line) : 0;
	while (buff[k] && buff[k] != '\n')
	{
		(*line)[len + k] = buff[k];
		k++;
	}
	(*line)[len + k] = 0;
	if (buff[k] == 0)
	{
		buff[j] = 0;
		return (0);
	}
	if (buff[k++] == '\n')
		while (buff[k])
			buff[j++] = buff[k++];
	buff[j] = 0;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		buff[4096][BUFFER_SIZE + 1];
	int				r;

	if ((r = 0) || fd < 0 || fd > 255 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = 0;
	if (buff[fd][r])
		if (new_line(line, buff[fd]))
		{
			*line = ft_realloc_finale(line);
			return (1);
		}
	while ((r = read(fd, buff[fd], BUFFER_SIZE)) > 0)
	{
		buff[fd][r] = 0;
		if (new_line(line, buff[fd]))
		{
			*line = ft_realloc_finale(line);
			return (1);
		}
	}
	if (r < 0)
		return (-1);
	*line = ft_realloc_finale(line);
	return (r);
}
