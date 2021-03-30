/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_S_F_C.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:35:08 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/16 15:17:30 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture_and_color_S(t_parse *parsing, char *line, int i)
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
	if(!(parsing->S = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z] && line[z] != ' ')
	{
		parsing->S[c] = line[z];
		c++;
		z++;
	}
	parsing->S[c] = '\0';
	parsing->check.S = ft_checkpath(parsing->S, line, parsing->check.S, i);
	return(0);
}

int	set_texture_and_color_F(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i])
	{	
		c++;
		i++;
	}
	if(!(parsing->F = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z])
	{
		parsing->F[c] = line[z];
		c++;
		z++;
	}
	parsing->F[c] = '\0';
	ft_warning(line,i);
	parsing->check.F = ft_checkcolor(parsing->F, parsing->f_color, parsing->check.F);
	return(0);
}

int	set_texture_and_color_C(t_parse *parsing, char *line, int i)
{
	int c;
	int z;

	c = 0;
	i += 2;
	while(line[i] == ' ')
		i++;
	z = i;
	while(line[i])
	{	
		c++;
		i++;
	}
	if(!(parsing->C = (char *)malloc(sizeof(char) * (c + 1))))
		return -1;
	c = 0;
	while(line[z])
	{
		parsing->C[c] = line[z];
		c++;
		z++;
	}
	parsing->C[c] = '\0';
	ft_warning(line,i);
	parsing->check.C = ft_checkcolor(parsing->C, parsing->c_color, parsing->check.C);
	return(0);
}
