/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:20:03 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/26 15:00:52 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_colorinit(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = 256;
		i++;
	}
	return (color);
}

void	listinit(t_parse *parsing)
{
	parsing->resx = 0;
	parsing->resy = 0;
	parsing->NO = NULL;
	parsing->SO = NULL;
	parsing->WE = NULL;
	parsing->EA = NULL;
	parsing->S = NULL;
	parsing->F = NULL;
	parsing->C = NULL;
	ft_colorinit(parsing->f_color);
	ft_colorinit(parsing->c_color);
	parsing->map = NULL;
	parsing->n_line = 1;
	parsing->check.resolution = 0;
	parsing->check.NO = 0;
	parsing->check.SO = 0;
	parsing->check.WE = 0;
	parsing->check.EA = 0;
	parsing->check.S = 0;
	parsing->check.F = 0;
	parsing->check.C = 0;
}

// void printstruct(t_parse *list)
// {
// 	int i = 0;

// 	printf("resx=%d\n", list->resx);
// 	printf("resy=%d\n", list->resy);
// 	printf("N0=%s\n", list->NO);
// 	printf("S0=%s\n", list->SO);
// 	printf("WE=%s\n", list->WE);
// 	printf("EA=%s\n", list->EA);
// 	printf("S=%s\n", list->S);
// 	printf("F=%s\n", list->F);
// 	printf("C=%s\n", list->C);
// 	while(list->map[i] != NULL)
// 	{
// 		printf("map=%s\n", list->map[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while(i < 3)
// 	{
// 		printf("fcolore%d: %d\t", i, list->f_color[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("\n");
// 	while(i < 3)
// 	{
// 		printf("ccolore%d: %d\t", i, list->c_color[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	ft_exit(t_win_data *win)
{
	mlx_destroy_image(win->mlx_ptr, win->text[0].img);
	mlx_destroy_image(win->mlx_ptr, win->text[1].img);
	mlx_destroy_image(win->mlx_ptr, win->text[2].img);
	mlx_destroy_image(win->mlx_ptr, win->text[3].img);
	mlx_destroy_image(win->mlx_ptr, win->img.img);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	system("killall afplay");
	exit(0);
	return (0);
}

void	move_up(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy + win->rayc.diry * movespeed)] \
	[(int)win->rayc.posx] == '0')
		win->rayc.posy += win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx + win->rayc.dirx * movespeed)] == '0')
		win->rayc.posx += win->rayc.dirx * movespeed;
}

void	move_down(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy - win->rayc.diry * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy -= win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx - win->rayc.dirx * movespeed)] == '0')
		win->rayc.posx -= win->rayc.dirx * movespeed;
}

void	rotate_left(t_win_data *win, double rotspeed)
{
	win->rayc.olddirx = win->rayc.dirx;
	win->rayc.dirx = win->rayc.dirx * cos(rotspeed) \
	 - win->rayc.diry * sin(rotspeed);
	win->rayc.diry = win->rayc.olddirx * sin(rotspeed) \
	 + win->rayc.diry * cos(rotspeed);
	win->rayc.oldplanex = win->rayc.planex;
	win->rayc.planex = win->rayc.planex * cos(rotspeed) \
	 - win->rayc.planey * sin(rotspeed);
	win->rayc.planey = win->rayc.oldplanex * sin(rotspeed) \
	 + win->rayc.planey * cos(rotspeed);
}

void	rotate_right(t_win_data *win, double rotspeed)
{
	win->rayc.olddirx = win->rayc.dirx;
	win->rayc.dirx = win->rayc.dirx * cos(-rotspeed) \
	 - win->rayc.diry * sin(-rotspeed);
	win->rayc.diry = win->rayc.olddirx * sin(-rotspeed) \
	 + win->rayc.diry * cos(-rotspeed);
	win->rayc.oldplanex = win->rayc.planex;
	win->rayc.planex = win->rayc.planex * cos(-rotspeed) \
	 - win->rayc.planey * sin(-rotspeed);
	win->rayc.planey = win->rayc.oldplanex * sin(-rotspeed) \
	 + win->rayc.planey * cos(-rotspeed);
}

void	move_left(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx + win->rayc.diry * movespeed)] == '0')
		win->rayc.posx += win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy - win->rayc.dirx * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy -= win->rayc.dirx * movespeed;
}

void	move_right(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx - win->rayc.diry * movespeed)] == '0')
		win->rayc.posx -= win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy + win->rayc.dirx * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy += win->rayc.dirx * movespeed;
}

void	player_move(t_win_data *win)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.15;
	rotspeed = 0.05;
	if (win->keys[126] || win->keys[13])
		move_up(win, movespeed);
	if (win->keys[125] || win->keys[1])
		move_down(win, movespeed);
	if (win->keys[124])
		rotate_left(win, rotspeed);
	if (win->keys[123])
		rotate_right(win, rotspeed);
	if (win->keys[0])
		move_left(win, movespeed);
	if (win->keys[2])
		move_right(win, movespeed);
}

void	ft_keyinit(t_win_data *win)
{
	int	i;

	i = 0;
	while (i < 128)
		win->keys[i++] = 0;
}

int	ft_keypress(int keycode, t_win_data *win)
{
	if (keycode == 53)
		ft_exit(win);
	if (keycode == 126 || keycode == 13)
		win->keys[keycode] = 1;
	if (keycode == 125 || keycode == 1)
		win->keys[keycode] = 1;
	if (keycode == 124)
		win->keys[keycode] = 1;
	if (keycode == 123)
		win->keys[keycode] = 1;
	if (keycode == 0)
		win->keys[keycode] = 1;
	if (keycode == 2)
		win->keys[keycode] = 1;
	if (keycode == 46)
		win->keys[keycode] = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_win_data *win)
{
	if (keycode == 126 || keycode == 13)
		win->keys[keycode] = 0;
	if (keycode == 125 || keycode == 1)
		win->keys[keycode] = 0;
	if (keycode == 124)
		win->keys[keycode] = 0;
	if (keycode == 123)
		win->keys[keycode] = 0;
	if (keycode == 0)
		win->keys[keycode] = 0;
	if (keycode == 2)
		win->keys[keycode] = 0;
	if (keycode == 46)
		win->keys[keycode] = 0;
	return (0);
}

void	ft_minimap(t_win_data *win)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	win->img.size_pixel = 7;
	while (win->resolution.x_max * win->img.size_pixel > win->resx)
		win->img.size_pixel--;
	while (win->resolution.n_line * win->img.size_pixel > win->resy)
		win->img.size_pixel--;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == '1')
				my_mlx_pixel_put2(&win->img, x * win->img.size_pixel,
				y * win->img.size_pixel, 0x00FFFFFF);
			if (win->map[y][x] == '2')
				my_mlx_pixel_put2(&win->img, x * win->img.size_pixel,
				y * win->img.size_pixel, 0x00FF0000);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put2(&win->img, (int)win->rayc.posx * win->img.size_pixel,
	(int)win->rayc.posy * win->img.size_pixel, 0x00FF00FF);
}

void	look_north(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 0;
	win->rayc.diry = -1;
	win->rayc.planex = 0.66;
	win->rayc.planey = 0;
	win->map[y][x] = '0';
}

void	look_west(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = -1;
	win->rayc.diry = 0;
	win->rayc.planex = 0;
	win->rayc.planey = -0.66;
	win->map[y][x] = '0';
}

void	look_east(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 1;
	win->rayc.diry = 0;
	win->rayc.planex = 0;
	win->rayc.planey = 0.66;
	win->map[y][x] = '0';
}

void	look_south(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 0;
	win->rayc.diry = 1;
	win->rayc.planex = -0.66;
	win->rayc.planey = 0;
	win->map[y][x] = '0';
}

void	ft_findplayer(t_win_data *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'N')
				look_north(win, y, x);
			if (win->map[y][x] == 'W')
				look_west(win, y, x);
			if (win->map[y][x] == 'E')
				look_east(win, y, x);
			if (win->map[y][x] == 'S')
				look_south(win, y, x);
			if (win->map[y][x] == '2')
				win->countsprite++;
			x++;
		}
		y++;
	}
}

void	malloc_sprite(t_win_data *win)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	win->spr = malloc(sizeof(t_sprite) * (win->countsprite));
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == '2')
			{
				win->spr[i].posx = x + 0.5;
				win->spr[i].posy = y + 0.5;
				win->spr[i].addr = win->text[4].addr;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	draw_dot(t_win_data *win, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (win->img.line_length * y) + (x * ((double)win->img.bpp / 8));
	win->img.addr[i] = b;
	win->img.addr[i + 1] = g;
	win->img.addr[i + 2] = r;
	win->img.addr[i + 3] = 0;
}

void	count_sprites(t_win_data *win)
{
	win->rayc.i = 0;
	while (win->rayc.i++ < win->countsprite)
		win->spr[win->rayc.i].sprdis = \
		((win->rayc.posx - win->spr[win->rayc.i].posx) \
		 * (win->rayc.posx - win->spr[win->rayc.i].posx) + \
		(win->rayc.posy - win->spr[win->rayc.i].posy) \
		 * (win->rayc.posy - win->spr[win->rayc.i].posy));
}

void	sort_sprites(t_win_data *win)
{
	t_sprite	tmp;
	int			i;
	int			j;
	int			c;

	c = win->countsprite - 1;
	j = 0;
	count_sprites(win);
	while (j < c)
	{
		i = c - 1;
		while (i >= j)
		{
			if (win->spr[i].sprdis < win->spr[i + 1].sprdis)
			{
				tmp = win->spr[i];
				win->spr[i] = win->spr[i + 1];
				win->spr[i + 1] = tmp;
			}
			i--;
		}
		j++;
	}
}

// void		ft_pavicielo(t_win_data *win)
// {
// 	// int x;
// 	// int y;
// 	// int cielo;
// 	// int pavi;
// 	win->text[5].img = mlx_xpm_file_to_image(win->mlx_ptr, win->text[5].relative_path, &win->text[5].img_width, &win->text[5].img_height);
// 	win->text[5].addr = (int *)mlx_get_data_addr(win->text[5].img, &win->text[5].bits_per_pixel, &win->text[5].line_length, &win->text[5].endian);
// 	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->text[5].img, 0, 0);
// 	// x = 0;
// 	// y = 0;
// 	// cielo = win->color[1];
// 	// pavi = win->color[0];
// 	// while(y < win->resy/2)
// 	// {
// 	// 	x = 0;
// 	// 	while(x < win->resx)
// 	// 	{
// 	// 		my_mlx_pixel_put(&win->image, x, y, cielo);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	// while(y < win->resy)
// 	// {
// 	// 	x = 0;
// 	// 	while(x < win->resx)
// 	// 	{
// 	// 		my_mlx_pixel_put(&win->image, x, y, pavi);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// }

int	ft_rendering(t_win_data *win)
{
	ft_raycasting(win);
	if (win->save == 0)
	{
		player_move(win);
		if (win->keys[46])
			ft_minimap(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img, 0, 0);
		mlx_do_sync(win->mlx_ptr);
	}
	return (0);
}

void	ft_checkxpm(t_win_data *win, int i)
{
	int	j;

	j = ft_strlen(win->text[i].relative_path);
	if (win->text[i].relative_path[j - 1] == 'm')
		win->text[i].xpm = 1;
	else
		win->text[i].xpm = 0;
}

void	init_textures(t_win_data *win)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		ft_checkxpm(win, i);
		i++;
	}
	i = 0;
	while (i <= 4)
	{
		if (win->text[i].xpm == 1)
			win->text[i].img = mlx_xpm_file_to_image(win->mlx_ptr, \
			win->text[i].relative_path, &win->text[i].w, &win->text[i].h);
		else
			win->text[i].img = mlx_png_file_to_image(win->mlx_ptr, \
			win->text[i].relative_path, &win->text[i].w, &win->text[i].h);
		win->text[i].addr = (int *)mlx_get_data_addr(win->text[i].img, \
		&win->text[i].bpp, &win->text[i].line_length, &win->text[i].end);
		i++;
	}
}

void	ft_screensize(t_win_data *win)
{
	mlx_get_screen_size(win->mlx_ptr,
	&win->resolution.sizex, &win->resolution.sizey);
	if (win->resx > (double)win->resolution.sizex)
		win->resx = (double)win->resolution.sizex;
	if (win->resx < 800)
		win->resx = 800;
	if (win->resy > (double)win->resolution.sizey)
		win->resy = (double)win->resolution.sizey;
	if (win->resy < 600)
		win->resy = 600;
}

void	init_window(t_win_data *win, t_parse *parsing)
{
	win->map = parsing->map;
	win->resx = parsing->resx;
	win->resy = parsing->resy;
	win->resolution.x_max = parsing->x_max;
	win->resolution.n_line = parsing->n_line;
	win->text[0].relative_path = parsing->WE;
	win->text[1].relative_path = parsing->EA;
	win->text[2].relative_path = parsing->NO;
	win->text[3].relative_path = parsing->SO;
	win->text[4].relative_path = parsing->S;
	win->color[0] = create_trgb(0, parsing->f_color[0], \
	parsing->f_color[1], parsing->f_color[2]);
	win->color[1] = create_trgb(0, parsing->c_color[0], \
	parsing->c_color[1], parsing->c_color[2]);
	win->countsprite = 0;
	win->mlx_ptr = mlx_init();
	win->img.img = mlx_new_image(win->mlx_ptr, win->resx, win->resy);
	win->img.addr = mlx_get_data_addr(win->img.img, \
	&win->img.bpp, &win->img.line_length, &win->img.endian);
	if (win->save == 0)
	{
		ft_screensize(win);
		win->win_ptr = mlx_new_window(win->mlx_ptr, \
		win->resx, win->resy, "cub3D");
	}
}

void	bmp_print(t_win_data *win, int fd)
{
	int	x;
	int	y;
	int	dst;
	int	resx;
	int	resy;

	resx = (int)win->resx;
	resy = (int)win->resy;
	y = resy - 1;
	dst = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < resx)
		{
			dst = (*(int *)(win->img.addr + \
			(y * win->img.line_length + (x * 4))));
			write(fd, &dst, 4);
			x++;
		}
		y--;
	}
}

void	bmp_header_2(t_win_data *win, int fd)
{
	int		plane;
	int		color;
	int		imgsize;
	int		resx;
	int		resy;

	plane = 1;
	color = 0;
	resx = (int)win->resx;
	resy = (int)win->resy;
	imgsize = resx * (resy - 1) * 4;
	write(fd, &plane, 2);
	write(fd, &win->img.bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &imgsize, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
}

void	bmp_header(t_win_data *win, int fd)
{
	int		filesize;
	int		offset;
	int		infoheader;
	int		resx;
	int		resy;

	offset = 54;
	infoheader = 40;
	resx = (int)win->resx;
	resy = (int)win->resy;
	filesize = resx * resy * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
	write(fd, &infoheader, 4);
	write(fd, &resx, 4);
	write(fd, &resy, 4);
}

int	ft_bitmap(t_win_data *win)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY, 00755);
	bmp_header(win, fd);
	bmp_header_2(win, fd);
	bmp_print(win, fd);
	close(fd);
	return (1);
}

void	init_save(t_win_data *win, t_parse *parsing, char **argv)
{
	ft_parsing_map(argv, parsing);
	init_window(win, parsing);
	init_textures(win);
	ft_findplayer(win);
	malloc_sprite(win);
	ft_keyinit(win);
	ft_rendering(win);
	ft_bitmap(win);
}

void	init_rayc(t_win_data *win, t_parse *parsing, char **argv)
{
	ft_parsing_map(argv, parsing);
	init_window(win, parsing);
	init_textures(win);
	ft_findplayer(win);
	malloc_sprite(win);
	system("afplay ./soundtracks/soundtrack.mp3 &");
	ft_keyinit(win);
	mlx_loop_hook(win->mlx_ptr, ft_rendering, win);
	mlx_hook(win->win_ptr, 17, 1L, ft_exit, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, ft_keypress, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, ft_keyrelease, win);
	mlx_loop(win->mlx_ptr);
}

int	save_check(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == save[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse		parsing;
	t_win_data	win;

	if (argc == 3 && (ft_strnstr(argv[1], ".cub") == 1) \
	 && (ft_strlen(argv[2]) == 6 && \
	(ft_strnstr(argv[2], "--save") == 1)))
	{
		win.save = 1;
		init_save(&win, &parsing, argv);
	}
	else if (argc == 2 && (ft_strnstr(argv[1], ".cub") == 1))
	{
		win.save = 0;
		init_rayc(&win, &parsing, argv);
	}
	else
		printf("Error\n");
}
