/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:27:08 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/01/25 17:10:16 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_line(char *memory, char *line)
{
	int i;
	int y;

	i = 0;
	if (!memory)
		return (NULL);
	while (memory[i] != '\n' && memory[i])
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	y = 0;
	while (y < i)
	{
		line[y] = memory[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*clean_memory(char *memory)
{
	int		i;
	char	*cleanedmem;
	int		y;

	i = 0;
	if (!memory)
		return (NULL);
	y = ft_strlen(memory);
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!(cleanedmem = (char *)malloc(sizeof(char) * (y - i + 1))))
		return (NULL);
	y = 0;
	while (memory[i])
	{
		i++;
		cleanedmem[y] = memory[i];
		y++;
	}
	cleanedmem[y] = '\0';
	free(memory);
	return (cleanedmem);
}

int		tofree(char *buff)
{
	free(buff);
	return (-1);
}

int		defr(char **line, int fd)
{
	int r;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		r = -1;
	else
		r = 1;
	return (r);
}

int		get_next_line(int fd, char **line)
{
	int				r;
	char			*buff;
	static char		*memory;

	r = defr(line, fd);
	if (r == -1 || !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(memory, '\n') && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
			return (tofree(buff));
		buff[r] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	*line = fill_line(memory, *line);
	memory = clean_memory(memory);
	if (r == 0)
	{
		free(memory);
		memory = NULL;
		return (0);
	}
	return (1);
}
