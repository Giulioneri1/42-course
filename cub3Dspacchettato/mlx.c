/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:11:56 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/16 15:17:52 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(img_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

void	my_mlx_pixel_put2(img_data *img, int x, int y, int color)
{
    char    *dst;
	int h;
	int l;
	int i;
    
	h = 0;
	l = 0;
	while(h < img->size_pixel)
	{
		l = 0;
		i = 0;
		while(l < img->size_pixel)
		{
			dst = img->addr + (y * img->line_length + (x + i) * (img->bpp / 8));
    		*(unsigned int*)dst = color;
			i++;
			l++;
		}
		h++;
		y++;
	}
	
}