/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:26:47 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/24 11:17:20 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkres(t_parse *parsing, char *line, int i)
{

	if(parsing->check.resolution == 1)
	{
		printf("Resolution Error: redefinition of res\n");
		exit(0);
	}
	while(line[i])
	{
		if(line[i] != ' ')
		{
			printf("Resolution Error: problem with args\n");
			exit(0);
		}
		i++;
	}
	if(parsing->resx == 0 && parsing->resy == 0)
	{
		printf("Resolution Error: both res are missing\n");
		exit(0);
	}
	if(parsing->resx == 0 || parsing->resy == 0)
	{
		printf("Resolution Error: one res is missing\n");
		exit(0);
	}
	parsing->check.resolution = 1;
}

int	ft_checkpath(char *parsing, char *line,int check, int i)
{
	int fd;

	if (check == 1)
	{
		printf("Path Error: redefinition of some textures\n");
		exit(0);
	}
	ft_warning(line,i);
	fd = open(parsing, O_RDONLY);
	if( fd == -1)
	{
		printf("Path Error: not valid file\n");
		exit(0);
	}
	close(fd);
	check = 1;
	return (check);
}

int	ft_checkcolor(char *str, int *color, int check)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if(!ft_isdigit(str[i]))
		{
			printf("Color Error: not valid color\n");
			exit(0);
		}
	while(str[i])// && (ft_isdigit(str[i]) || str[i] == ','))
	{
		if(str[i] && ft_isdigit(str[i]))
        {
            if(color[x] == 256)
                color[x] = 0;
			color[x] = (10 * color[x]) + (str[i] - '0');
        }
		else if(str[i] && !ft_isdigit(str[i]))
		{
			if(str[i] == ',')
				x++;
			else if(str[i] != ' ')
			{
				printf("Color Error: not valid color\n");
				exit(0);
			}
		}
		i++;
	}
    if(x != 2)
    {
                printf("Error\n");
                exit(0);
    }
	check = ft_checkvalidcolor(color, check);
	return (check);
}

int ft_checkvalidcolor(int *color, int check)
{
	int i;

	i = 0;
	if(check == 1)
	{
		printf("Color Error: redefinition of some color\n");
		exit(0);
	}
	while(i < 3)
	{
		if(color[i] > 255)
		{
			printf("Color Error: not valid color range\n");
			exit(0);
		}
		i++;
	}
	check = 1;
	return(check);
}

void ft_warning(char *line, int i)
{
	while(line[i])
	{
		if(line[i] != ' ')
		{
			printf("Error: too many args\n");
			exit(0);
		}
		i++;

	}
}
