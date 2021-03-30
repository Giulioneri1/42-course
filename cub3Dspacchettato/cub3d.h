/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:21:25 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/03/27 11:30:40 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <math.h>

# define BUFFER_SIZE 1024

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bpp;
    int         line_length;
    int         endian;
	int			size_pixel;
}               img_data;

typedef	struct s_engine
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double 		sdx;
	double 		sdy;
	double 		ddx;
	double 		ddy;
	int 		mapx;
	int 		mapy;
	int 		stepx;
	int 		stepy;
	int 		hit;
	int 		side;
	double 		pwd;
	int 		drawstart;
	int 		drawend;
	int 		lineh;
	double		olddirx;
	double		oldplanex;
	float 		raydirx0;
	float 		raydirx1;
	float 		raydiry0;
	float 		raydiry1;
	float 		posz;
	float 		rowdistance;
	float 		floorstepx;
	float 		floorstepy;
	float 		floorx;
	float 		floory;
	int 		cellx;
	int 		celly;
	int 		tx;
	int 		ty;
	double 		wallx;
	int 		texx;
	double 		step;
	double 		texpos;
	int 		texy;
	double 		spritex;
	double 		spritey;
	double 		invdet;
	double 		transformx;
	double 		transformy;
	int 		sprscrx;
	int 		sprh;
	int 		drawstarty;
	int 		drawendy;
	int 		sprw;
	int 		drawstartx;
	int 		drawendx;
	int 		stripe;
	int 		d;
	unsigned int color;
	int 			x;
	int 			y;
	int 			i;
	
	

}				t_engine;

typedef	struct s_texture
{
    void    *img;
	int    	*addr;
    char    *relative_path;
    int     w;
    int     h;
	int     bpp;
    int     line_length;
    int     end;
	int		xpm;
}				t_texture;

typedef struct	s_sprite
{
	double		posx;
	double		posy;
	double 		sprdis;
	int    		*addr;

	
}				t_sprite;

typedef struct r_resolution
{
	int			sizex;
	int			sizey;
	int			x_max;
	int			n_line;
}				t_res;


typedef struct 	w_data
{
	void 		*mlx_ptr;
	void 		*win_ptr;
	img_data 	img;
	img_data	minimap;
	t_texture	text[6];
	char		**map;
	t_engine	rayc;
	double		resx;
	double		resy;
	char 		keys[128];
	int			color[2];
	int			countsprite;
	t_sprite	*spr;
	t_res		resolution;
	int			save;
		
}				win_data;

typedef struct	c_check
{
	int resolution;
	int NO;
	int SO;
	int WE;
	int EA;
	int S;
	int F;
	int C;

} 				t_check;

typedef struct s_parse
{
	int resx;
	int resy;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *S;
	char *F;
	char *C;
	int f_color[3];
	int	c_color[3];
	char **map;
	int n_line;
	int x_max;
	t_check check;

	
} 				t_parse;

void	ft_multipleray(win_data *win);
void	my_mlx_pixel_put2(img_data *img, int x, int y, int color);
void    my_mlx_pixel_put(img_data *img, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_next_line(int fd, char **line);
char	*fill_line(char *memory, char *line);
char	*clean_memory(char *memory);
int		tofree(char *buff);
int		defr(char **line, int fd);
int		ft_strlen(char *line);
int		ft_strchr(char *line, char c);
char	*ft_strjoin(char *s1, char *s2);
void 	ft_parsing_map(char **argv, t_parse *list);
int		ft_isdigit(int c);
void 	ft_parsing_map(char **argv, t_parse *list);
void	ft_checkparsing(t_parse *list, char *line);
void 	listinit(t_parse *list);
void	set_res(t_parse *list, char *line, int i);
int		set_texture_and_color_NO(t_parse *list, char *line, int i);
int		set_texture_and_color_SO(t_parse *list, char *line, int i);
int		set_texture_and_color_WE(t_parse *list, char *line, int i);
int		set_texture_and_color_EA(t_parse *list, char *line, int i);
int		set_texture_and_color_S(t_parse *list, char *line, int i);
int		set_texture_and_color_F(t_parse *list, char *line, int i);
int		set_texture_and_color_C(t_parse *list, char *line, int i);
void 	printstruct(t_parse *list);
int 	check_var(t_parse *list);
int 	check_emptyline(char *line, t_parse *list);
void	ft_map(t_parse *list, char *line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_checkres(t_parse *list, char *line, int i);
int		ft_checkpath(char *list, char *line, int check, int i);
int		*ft_colorinit(int *color);
int		ft_checkcolor(char *str, int *color, int check);
int 	ft_checkvalidcolor(int *color, int check);
void 	ft_warning(char *line, int i);
void 	ft_checkmap(t_parse *list);
int		ft_frame(win_data *win);
int		ft_keyhook(int keycode, win_data *win);
void	ft_ray(win_data *win, double angle);





//3 

void	ft_findplayer(win_data *win);
void	ft_raycasting(win_data *win);
int		ft_rendering(win_data *win);
void	ft_pavicielo(win_data *win);
void	ft_minimap(win_data *win);
void	malloc_sprite(win_data *win);
void 	ft_checkfirstlast(t_parse *parsing);
void 	ft_checkborder(t_parse *parsing);
void	ft_checkplayer(t_parse *parsing);
void	ft_screensize(win_data *win);
void	ft_checkminimap(t_parse *parsing);
void	draw_dot(win_data *win, int x, int y, int color);
void	count_sprites(win_data *win);
void 	sort_sprites(win_data *win);
int		ft_strnstr(const char *hay, const char *ndl);
void	ft_error(char *errormsg);
void    ft_checkline(t_parse *parsing, int y, int x);

#endif