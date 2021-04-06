/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:12:31 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/26 14:04:33 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_textured_floorceiling(t_win_data *win)
{
	win->rayc.raydirx0 = win->rayc.dirx - win->rayc.planex;
	win->rayc.raydiry0 = win->rayc.diry - win->rayc.planey;
	win->rayc.raydirx1 = win->rayc.dirx + win->rayc.planex;
	win->rayc.raydiry1 = win->rayc.diry + win->rayc.planey;
	win->rayc.posz = 0.5 * win->resy;
	win->rayc.rowdistance = win->rayc.posz / (win->rayc.y - win->resy / 2);
	win->rayc.floorstepx = win->rayc.rowdistance * \
	(win->rayc.raydirx1 - win->rayc.raydirx0) / win->resx;
	win->rayc.floorstepy = win->rayc.rowdistance * \
	(win->rayc.raydiry1 - win->rayc.raydiry0) / win->resx;
	win->rayc.floorx = win->rayc.posx + win->rayc.rowdistance * \
	win->rayc.raydirx0;
	win->rayc.floory = win->rayc.posy + win->rayc.rowdistance * \
	win->rayc.raydiry0;
}

void	floor_ceiling(t_win_data *win)
{
	win->rayc.y = win->resy / 2 + 1;
	while (win->rayc.y < win->resy)
	{
		set_textured_floorceiling(win);
		win->rayc.x = 0;
		while (win->rayc.x < win->resx)
		{
			win->rayc.cellx = (int)(win->rayc.floorx);
			win->rayc.celly = (int)(win->rayc.floory);
			win->rayc.tx = (int)(win->text[0].w * \
			(win->rayc.floorx - win->rayc.cellx)) & (win->text[0].w - 1);// CAMBIARE TEXTURE PAVIMENTO
			win->rayc.ty = (int)(win->text[0].h * \
			(win->rayc.floory - win->rayc.celly)) & (win->text[0].h - 1);// CAMBIARE TEXTURE PAVIMENTO
			win->rayc.floorx += win->rayc.floorstepx;
			win->rayc.floory += win->rayc.floorstepy;
			// floor
			//win->rayc.color = (unsigned int)win->text[0].addr[win->text[0].img_width * win->rayc.ty + win->rayc.tx];  // PER CARICARE TEXTURE PAVIMENTO
			win->rayc.color = win->color[0];
			draw_dot(win, win->rayc.x, win->rayc.y, win->rayc.color);
			//ceiling
			//win->rayc.color = (unsigned int)win->text[1].addr[win->text[1].img_width * win->rayc.ty + win->rayc.tx];  // PER CARICARE TEXTURE SOFFITTO
			win->rayc.color = win->color[1];
			draw_dot(win, win->rayc.x, win->resy - \
			win->rayc.y - 1, win->rayc.color);
			++win->rayc.x;
		}
		++win->rayc.y;
	}
}

void	ray_calculations(t_win_data *win)
{
	win->rayc.camerax = 2 * win->rayc.x / (double)win->resx - 1;
	win->rayc.raydirx = win->rayc.dirx + win->rayc.planex * win->rayc.camerax;
	win->rayc.raydiry = win->rayc.diry + win->rayc.planey * win->rayc.camerax;
	win->rayc.mapx = (int)win->rayc.posx;
	win->rayc.mapy = (int)win->rayc.posy;
	win->rayc.ddx = fabs(1 / win->rayc.raydirx);
	win->rayc.ddy = fabs(1 / win->rayc.raydiry);
	win->rayc.hit = 0;
	if (win->rayc.raydirx < 0)
	{
		win->rayc.stepx = -1;
		win->rayc.sdx = (win->rayc.posx - win->rayc.mapx) * win->rayc.ddx;
	}
	else
	{
		win->rayc.stepx = 1;
		win->rayc.sdx = (win->rayc.mapx + 1.0 - win->rayc.posx) * win->rayc.ddx;
	}
	if (win->rayc.raydiry < 0)
	{
		win->rayc.stepy = -1;
		win->rayc.sdy = (win->rayc.posy - win->rayc.mapy) * win->rayc.ddy;
	}
	else
	{
		win->rayc.stepy = 1;
		win->rayc.sdy = (win->rayc.mapy + 1.0 - win->rayc.posy) * win->rayc.ddy;
	}
}

void	perform_dda(t_win_data *win)
{
	while (win->rayc.hit == 0)
	{
		if (win->rayc.sdx < win->rayc.sdy)
		{
			win->rayc.sdx += win->rayc.ddx;
			win->rayc.mapx += win->rayc.stepx;
			win->rayc.side = 0;
		}
		else
		{
			win->rayc.sdy += win->rayc.ddy;
			win->rayc.mapy += win->rayc.stepy;
			win->rayc.side = 1;
		}
		if (win->map[win->rayc.mapy][win->rayc.mapx] == '1')
			win->rayc.hit = 1;
	}
}

void	set_directions(t_win_data *win)
{
	if (win->rayc.side == 0 && win->rayc.raydirx < 0) //OVEST
		win->rayc.i = 0;
	if (win->rayc.side == 0 && win->rayc.raydirx > 0) //EST
		win->rayc.i = 1;
	if (win->rayc.side == 1 && win->rayc.raydiry < 0) //NORD
		win->rayc.i = 2;
	if (win->rayc.side == 1 && win->rayc.raydiry > 0) //SUD
		win->rayc.i = 3;
}

void	set_text_variables(t_win_data *win)
{
	if (win->rayc.side == 0)
		win->rayc.wallx = win->rayc.posy + win->rayc.pwd * win->rayc.raydiry;
	else
		win->rayc.wallx = win->rayc.posx + win->rayc.pwd * win->rayc.raydirx;
	win->rayc.wallx -= floor((win->rayc.wallx));
	win->rayc.texx = (int)(win->rayc.wallx * (double)win->text[win->rayc.i].w);
	if (win->rayc.side == 0 && win->rayc.raydirx > 0)
		win->rayc.texx = win->text[win->rayc.i].w - win->rayc.texx - 1;
	if (win->rayc.side == 1 && win->rayc.raydiry < 0)
		win->rayc.texx = win->text[win->rayc.i].w - win->rayc.texx - 1;
	win->rayc.step = 1.0 * win->text[win->rayc.i].h / win->rayc.lineh;
	win->rayc.texpos = (win->rayc.drawstart - win->resy / 2 + \
	win->rayc.lineh / 2) * win->rayc.step;
}

void	pre_draw_calculations(t_win_data *win)
{
	if (win->rayc.side == 0)
		win->rayc.pwd = (win->rayc.mapx - win->rayc.posx + \
		(1 - win->rayc.stepx) / 2) / win->rayc.raydirx;
	else
		win->rayc.pwd = (win->rayc.mapy - win->rayc.posy + \
		(1 - win->rayc.stepy) / 2) / win->rayc.raydiry;
	win->rayc.lineh = (int)(win->resy / win->rayc.pwd);
	win->rayc.drawstart = win->resy / 2 - win->rayc.lineh / 2;
	if (win->rayc.drawstart < 0)
		win->rayc.drawstart = 0;
	win->rayc.drawend = win->rayc.lineh / 2 + win->resy / 2;
	if (win->rayc.drawend >= win->resy)
		win->rayc.drawend = win->resy - 1;
	set_directions(win);
	set_text_variables(win);
}

void	wall_casting(t_win_data *win, double *zbuffer)
{
	win->rayc.x = 0;
	while (win->rayc.x < win->resx)
	{
		ray_calculations(win);
		perform_dda(win);
		pre_draw_calculations(win);
		win->rayc.y = win->rayc.drawstart;
		while (win->rayc.y < win->rayc.drawend)
		{
			win->rayc.texy = (int)win->rayc.texpos & \
			(win->text[win->rayc.i].h - 1);
			win->rayc.texpos += win->rayc.step;
			win->rayc.color = (unsigned int)win->text[win->rayc.i].addr \
			[win->text[win->rayc.i].h * win->rayc.texy + win->rayc.texx];
			draw_dot(win, win->rayc.x, win->rayc.y, win->rayc.color);
			win->rayc.y++;
		}
		zbuffer[win->rayc.x] = win->rayc.pwd;
		win->rayc.x++;
	}
}

void	sprite_position(t_win_data *win)
{
	win->rayc.spritex = win->spr[win->rayc.i].posx - win->rayc.posx;
	win->rayc.spritey = win->spr[win->rayc.i].posy - win->rayc.posy;
	win->rayc.invdet = 1.0 / \
	(win->rayc.planex * win->rayc.diry - win->rayc.dirx * win->rayc.planey);
	win->rayc.transformx = win->rayc.invdet * \
	(win->rayc.diry * win->rayc.spritex - win->rayc.dirx * win->rayc.spritey);
	win->rayc.transformy = win->rayc.invdet * \
	((-win->rayc.planey) * win->rayc.spritex + \
	win->rayc.planex * win->rayc.spritey);
	win->rayc.sprscrx = (int)((win->resx / 2) * \
	(1 + win->rayc.transformx / win->rayc.transformy));
}

void	sprite_calculations(t_win_data *win)
{
	sprite_position(win);
	win->rayc.sprh = (abs((int)(win->resy / win->rayc.transformy)));
	win->rayc.drawstarty = -win->rayc.sprh / 2 + win->resy / 2;
	if (win->rayc.drawstarty < 0)
		win->rayc.drawstarty = 0;
	win->rayc.drawendy = win->rayc.sprh / 2 + win->resy / 2;
	if (win->rayc.drawendy >= win->resy)
		win->rayc.drawendy = win->resy - 1;
	win->rayc.sprw = (abs((int)(win->resy / win->rayc.transformy)));
	win->rayc.drawstartx = -win->rayc.sprw / 2 + win->rayc.sprscrx;
	if (win->rayc.drawstartx < 0)
		win->rayc.drawstartx = 0;
	win->rayc.drawendx = win->rayc.sprw / 2 + win->rayc.sprscrx;
	if (win->rayc.drawendx >= win->resx)
		win->rayc.drawendx = win->resx - 1;
	win->rayc.stripe = win->rayc.drawstartx;
}

void	draw_sprites(t_win_data *win, double *zbuffer)
{
	win->rayc.i = 0;
	while (win->rayc.i < win->countsprite)
	{
		sprite_calculations(win);
		while (win->rayc.stripe < win->rayc.drawendx)
		{
			win->rayc.texx = (int)(256 * (win->rayc.stripe - \
			(-win->rayc.sprw / 2 + win->rayc.sprscrx)) \
			 * win->text[4].w / win->rayc.sprw) / 256;
			if (win->rayc.transformy > 0 && win->rayc.stripe > 0 && \
			win->rayc.stripe < win->resx && \
			win->rayc.transformy < zbuffer[win->rayc.stripe])
			{
				win->rayc.y = win->rayc.drawstarty;
				while (win->rayc.y < win->rayc.drawendy)
				{
					win->rayc.d = (win->rayc.y) * 256 - win->resy * 128 \
					 + win->rayc.sprh * 128;
					win->rayc.texy = ((win->rayc.d * win->text[4].h) / \
					win->rayc.sprh) / 256;
					win->rayc.color = (unsigned int)win->spr[win->rayc.i].addr \
					[win->text[4].w * win->rayc.texy + win->rayc.texx];
					if ((win->rayc.color & 0x00FFFFFF) != 0)
						draw_dot(win, win->rayc.stripe, win->rayc.y, \
						win->rayc.color);
					win->rayc.y++;
				}
			}
			win->rayc.stripe++;
		}
		win->rayc.i++;
	}
}

void	ft_raycasting(t_win_data *win)
{
	double	*zbuffer;

	zbuffer = malloc(sizeof(double) * win->resx + 1);
	floor_ceiling(win);
	wall_casting(win, zbuffer);
	sort_sprites(win);
	draw_sprites(win, zbuffer);
	free(zbuffer);
}
