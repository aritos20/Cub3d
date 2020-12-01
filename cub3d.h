/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:05:59 by antmarti          #+#    #+#             */
/*   Updated: 2020/03/10 12:48:11 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_W 13
# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# define BYTES_PER_PIXEL 4

typedef struct		s_cub
{
	double			posx;
	double			posy;
	double			dirx;
	double			olddirx;
	double			diry;
	double			planex;
	double			oldplanex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_info;
	int				bpp;
	int				ls;
	int				endian;
	double			rotspeed;
	double			movespeed;
	int				a;
	int				s;
	int				w;
	int				d;
	int				f;
	int				c;
	int				right;
	int				left;
	int				**texture;
	int				**map;
	int				screenheight;
	int				screenwidth;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_sprite;
	int				floor_color;
	int				ceiling_color;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	int				p;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	double			*zbuffer;
	double			*spritex;
	double			*spritey;
	double			spriteposx;
	double			spriteposy;
	int				*spriteorder;
	double			*spritedistance;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				sprites_numb;
	int				textheight;
	int				textwidth;
	char			orientation;
	int				*n_text;
	int				*n_text_info;
	int				*n_text2;
	int				*n_text_info2;
	int				*n_text3;
	int				*n_text_info3;
	int				*n_text4;
	int				*n_text_info4;
	int				*n_text5;
	int				*n_text_info5;
	int				*n_text6;
	int				*n_text_info6;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				stripe;
	int				texx2;
	int				texy2;
	int				y_sprite;
	int				d_sprite;
	int				map_h;
	int				map_w;
	int				music;
	int				counter;
}					t_cub;

void				ft_read_map(t_cub *cub, char *map_path);
void				ft_floor_ceiling(t_cub *cub);
void				ft_draw_floor(t_cub *cub, int x, int y);
void				ft_view(t_cub *cub);
void				ft_init(t_cub *cub);
void				raycasting_init(t_cub *cub, int x, int y, int z);
void				raycasting_first_part(t_cub *cub, int x);
void				raycasting_second_part(t_cub *cub);
void				raycasting_third_part(t_cub *cub);
void				raycasting_fourth_part(t_cub *cub, int *y);
void				raycasting_fifth_part(t_cub *cub, int y, int x);
void				ft_textures(t_cub *cub);
void				ft_assign_textures(t_cub *cub);
void				ft_create_image(t_cub *cub);
void				ft_create_image2(t_cub *cub, int width, int height);
int					ft_exit_hook(void *param);
void				ft_exit_hook2(t_cub *cub);
void				ft_mlx(t_cub *cub);
int					move_player(void *param);
void				rotate_player_to_left(t_cub *cub);
void				rotate_player_to_right(t_cub *cub);
void				move_player_to_right(t_cub *cub);
void				move_player_to_left(t_cub *cub);
void				move_player_back(t_cub *cub);
void				move_player_forward(t_cub *cub);
int					key_pressed(int key, void *param);
int					key_released(int key, void *param);
void				key_f(t_cub *cub);
void				ft_set_direction(t_cub *cub);
void				ft_set_direction_west(t_cub *cub);
void				ft_sprites(t_cub *cub);
void				sprites_numb_and_order(t_cub *cub, int x, double temp);
void				sprites_first_part(t_cub *cub, int x);
void				draw_sprites(t_cub *cub);
int					ft_strlen(char *s);
char				*ft_strdup(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, int start, int len);
char				*ft_strchr(char *s, int c);
int					get_next_line(char **line, int fd);
void				ft_rgb_to_hex(char *buff_color, int time, int *pointer,
t_cub *cub);
int					ft_append(int ret, char **file, int fd, char *buffer);
int					ft_saver(char **file, char **line);
int					ft_return_0(char *buffer, char **line);
int					ft_return_1(char *buffer);
void				ft_loop(t_cub *cub, char *line);
int					ft_loop2(t_cub *cub, char *line, int j, int n);
void				ft_map_size(t_cub *cub);
void				ft_map(t_cub *cub, char *line, char *map_path);
char				*ft_path(char *line);
void				ft_color(char *line, int *type, t_cub *cub);
void				ft_read_map2(t_cub *cub, char *map_path, char *line);
void				ft_resolution(t_cub *cub, char *line);
int					save_bmp(t_cub *cub);
int					ft_map_error(t_cub *cub);
int					ft_map_error_2(t_cub *cub, int i, int j);
int					ft_path_duplicate(t_cub *cub, char *path);
int					ft_color_duplicate(t_cub *cub, int color);
void				ft_path_check(t_cub *cub);
int					ft_atoi(const char *str);
void				ft_error(t_cub *cub, int i);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_error_2(t_cub *cub, int i);
int					ft_loop3(t_cub *cub, char *line, int n, int *j);
void				ft_read_map3(t_cub *cub, char *line, int i);
void				ft_read_map4(t_cub *cub, char *line, int i);
#endif
