/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_res_4var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:10:50 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/16 15:16:58 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_res(t_parse *parsing, char *line, int i)
{
	i++;
	while(line[i] == ' ')
		i++;
		while(ft_isdigit(line[i]))
		{
			parsing->resx = (10 * parsing->resx) + (line[i] - '0');
			i++;
		}
	while(line[i] == ' ')
		i++;
		while(ft_isdigit(line[i]))
		{
			parsing->resy = (10 * parsing->resy) + (line[i] - '0');
			i++;
		}
	ft_checkres(parsing, line, i);
}

int	set_texture_and_color_NO(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i] && line[i] != ' ')
	{	
		c++;
		i++;
	}
	if(!(parsing->NO = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z] && line[z] != ' ')
	{
		parsing->NO[c] = line[z];
		c++;
		z++;
	}
	parsing->NO[c] = '\0';
	parsing->check.NO = ft_checkpath(parsing->NO, line, parsing->check.NO, i);
	return(0);
}

int	set_texture_and_color_SO(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i] && line[i] != ' ')
	{	
		c++;
		i++;
	}
	if(!(parsing->SO = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z] && line[z] != ' ')
	{
		parsing->SO[c] = line[z];
		c++;
		z++;
	}
	parsing->SO[c] = '\0';
	parsing->check.SO = ft_checkpath(parsing->SO, line, parsing->check.SO, i);
	return(0);
}

int	set_texture_and_color_WE(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i] && line[i] != ' ')
	{	
		c++;
		i++;
	}
	if(!(parsing->WE = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z] && line[z] != ' ')
	{
		parsing->WE[c] = line[z];
		c++;
		z++;
	}
	parsing->WE[c] = '\0';
	parsing->check.WE = ft_checkpath(parsing->WE, line, parsing->check.WE, i);
	return(0);
}

int	set_texture_and_color_EA(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i] && line[i] != ' ')
	{	
		c++;
		i++;
	}
	if(!(parsing->EA = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z] && line[z] != ' ')
	{
		parsing->EA[c] = line[z];
		c++;
		z++;
	}
	parsing->EA[c] = '\0';
	parsing->check.EA = ft_checkpath(parsing->EA, line, parsing->check.EA, i);
	return(0);
}