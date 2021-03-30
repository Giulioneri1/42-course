/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:59:17 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/27 10:23:29 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_checkfirstlast(t_parse *parsing)
{
	int x;

	x = 0;
	while(parsing->map[0][x])
	{
		if(parsing->map[0][x] != ' ' && parsing->map[0][x] != '1')
		{
			printf("Map error: problem in first line\n");
			exit(0);
		}
		x++;
	}
	x = 0;
	while(parsing->map[parsing->n_line - 1][x])
	{
		if(parsing->map[parsing->n_line - 1][x] != ' ' && parsing->map[parsing->n_line - 1][x] != '1')
		{
			printf("Map error: problem in last line\n");
			exit(0);
		}
		x++;
	}
}

int ft_isvalidchar(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	ft_checkupdown(t_parse *parsing, int y, int x)
{
	if (parsing->map[y - 1][x] != '1' || parsing->map[y + 1][x] != '1')
	{
		printf("Map error: problem on the map border (2)\n");
		exit(0);
	}
}

void ft_checkborder(t_parse *parsing)
{
	int x;
	int y;

	
	y = 0;
	while(y < parsing->n_line)
	{
		x = ft_strlen(parsing->map[y]);
		if(parsing->map[y][0] != '1' && parsing->map[y][0] != ' ')
		{
			printf("Map border error: problem on the %d line\n", y);
			exit(0);
		}
		if(parsing->map[y][x - 1] != '1' && parsing->map[y][x - 1] != ' ')
		{
			printf("Map border error: problem on the %d line\n", y);
			exit(0);
		}
		y++;
	}
}
		
int		ft_checkchar(char c)
{
	if (c == '0' || c == '2' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	ft_crosscheck(t_parse *parsing)
{
	int x;
	int y;

	y = 1;
	while (parsing->map[y])
	{
		x = 1;
		while (parsing->map[y][x])
		{
			if (ft_checkchar(parsing->map[y][x]))
			{
                ft_checkline(parsing, y, x);
				if (ft_isvalidchar(parsing->map[y][x - 1]) == 0
				|| ft_isvalidchar(parsing->map[y][x + 1]) == 0
				|| ft_isvalidchar(parsing->map[y - 1][x]) == 0
				|| ft_isvalidchar(parsing->map[y + 1][x]) == 0)
				{
					printf("Map error: Invalid map around [y = %d, x = %d]\n", y , x);
					exit(0);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_checkplayer(t_parse *parsing)
{
	int x;
	int y;
	int c;

	y = 0;
	c = 0;
	while (parsing->map[y])
	{
		x = 0;
		while (parsing->map[y][x])
		{
			if(parsing->map[y][x] == 'N'|| parsing->map[y][x] == 'S' || parsing->map[y][x] == 'W' || parsing->map[y][x] == 'E')
				c++;
			x++;
		}
		y++;
	}
	if(c != 1)
	{
		printf("Error with player\n");
		exit(0);
	}

}
void	ft_checkminimap(t_parse *parsing)
{
	int y;
	int min;

	y = 0;
	parsing->x_max = 0;
	while(y < parsing->n_line)
	{
		min = ft_strlen(parsing->map[y]);
		if(min > parsing->x_max)
			parsing->x_max = min;
		y++;
	}
}


void        ft_checkline(t_parse *parsing, int y, int x)
{
    int l;


    if((x > (l = ft_strlen(parsing->map[y - 1]))))
        ft_error("Error nuovo");
    if((x > (l = ft_strlen(parsing->map[y + 1]))))
        ft_error("Error nuovo1");
}

void	ft_checkmap(t_parse *parsing)
{
	if(parsing->map == NULL)
	{
		printf("Error: Invalid map\n");
		exit(0);
	}
	ft_checkfirstlast(parsing);
	ft_checkborder(parsing);
	ft_crosscheck(parsing);
	ft_checkplayer(parsing);
	ft_checkminimap(parsing);

}
