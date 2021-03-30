/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:53:26 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/26 14:57:57 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkparsing(t_parse *parsing, char *line)
{
	int i;

	i = 0;
	
		while(line[i] == ' ')
			i++;
		if(line[i] == 'R')
			set_res(parsing, line, i);
		else if(line[i] == 'N' && line[i + 1] == 'O')
			set_texture_and_color_NO(parsing, line, i);
		else if(line[i] == 'S' && line[i + 1] == 'O')
			set_texture_and_color_SO(parsing, line, i);
		else if(line[i] == 'W' && line[i + 1] == 'E')
			set_texture_and_color_WE(parsing, line, i);
		else if(line[i] == 'E' && line[i + 1] == 'A')
			set_texture_and_color_EA(parsing, line, i);
		else if(line[i] == 'S' && line[i + 1] == ' ')
			set_texture_and_color_S(parsing, line, i);
		else if(line[i] == 'F' && line[i + 1] == ' ')
			set_texture_and_color_F(parsing, line, i);
		else if(line[i] == 'C' && line[i + 1] == ' ')
			set_texture_and_color_C(parsing, line, i);
        else if(line[i] != ' ' && line[i] != '\0')
			ft_error("Parsing Error");
}


int check_var(t_parse *parsing)
{
	if(parsing->resx != 0 && parsing->resy != 0 && parsing->NO != NULL && parsing->SO != NULL && parsing->WE != NULL && parsing->EA != NULL && parsing->S != NULL && parsing->F != NULL && parsing->C != NULL)
		return 1;
	else
		return 0;
}

int check_emptyline(char *line, t_parse *parsing)
{
	if(parsing->map != NULL)
		return 0;
	if(line[0] == '\0')
			return (1);
	while(*line == ' ')
		line++;
	if(*line == '1' || *line == '0')
			return (0);
	return(1);
}


void ft_realloc(t_parse *parsing, char *line)
{
	char **tmp;
	int i;
	int c;
	int n_line;

	//printf("line: %s\n", line);
	c = 0;
	n_line = parsing->n_line;
	if(!(tmp = (char **)malloc(sizeof(char *) * (parsing->n_line + 1))))
		return;
	parsing->map[parsing->n_line] = NULL;
	while(n_line)
	{
		i = ft_strlen(parsing->map[c]);
		if(!(tmp[c] = (char *)malloc(sizeof(char) * (i + 1))))
			return;
		tmp[c] = ft_memcpy(tmp[c], parsing->map[c], i);
		tmp[c][i] = '\0';
		free(parsing->map[c]);
		c++;
		n_line--;
	}
	free(parsing->map);
	n_line = parsing->n_line;
	parsing->n_line++;
	if(!(parsing->map = (char **)malloc(sizeof(char *) * (parsing->n_line + 1))))
		return;
	parsing->map[parsing->n_line] = NULL;
	c = 0;
	while(n_line)
	{
		i = ft_strlen(tmp[c]);
		if(!(parsing->map[c] = (char *)malloc(sizeof(char) * (i + 1))))
			return;
		parsing->map[c] = ft_memcpy(parsing->map[c], tmp[c], i);
		parsing->map[c][i] = '\0';
		free(tmp[c]);
		c++;
		n_line--;
	}
	free(tmp);
	i = ft_strlen(line);
	if(!(parsing->map[c] = (char *)malloc(sizeof(char) * (i + 1))))
			return;
	parsing->map[c] = ft_memcpy(parsing->map[c], line, i);
	parsing->map[c][i] = '\0';	
}



void ft_map(t_parse *parsing, char *line)
{
	int i;

	if(parsing->map == NULL)
	{
		if(!(parsing->map = (char **)malloc(sizeof(char *) * (2))))
			return;
		parsing->map[1] = NULL;
		i = ft_strlen(line);
		if(!(parsing->map[0] = (char *)malloc(sizeof(char) * (i + 1))))
			return;
		parsing->map[0] = ft_memcpy(parsing->map[0], line, i);
		parsing->map[0][i] = '\0';
	}
	else
		ft_realloc(parsing, line);
	//	printf("LINEA %s\n", line);
	//	free(parsing->map[0]);

}

void ft_parsing_map(char **argv, t_parse *parsing)
{
	int fd;
	char *line;
	int r;
	int c = 1;

	r = 1;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		ft_error("Error with .cub file");
	listinit(parsing);
	while(r)
	{
		r = get_next_line(fd, &line);
		if(check_emptyline(line,parsing) == 0)
			ft_map(parsing, line);
		else
			ft_checkparsing(parsing, line);
		free(line);
		c++;
	}
	if(!check_var(parsing))
		ft_error("Map Error: missing some info");
	close(fd);
	ft_checkmap(parsing);
}
