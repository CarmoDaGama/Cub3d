/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:12:04 by rpambo            #+#    #+#             */
/*   Updated: 2025/01/11 22:44:42 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <time.h>
# include <mlx.h>
# include <mlx_int.h>
# include "keys.h"
# include "libft.h"
# include <limits.h>

//# define LARGE_DISTANCE 1e30
# define SCREENWIDTH  1920
# define SCREENHEIGHT 1080

typedef struct s_text
{
	void	*textures[4];
	int		width[4];
	int		height[4];
	double	wall_hit_pos;
	double	step;
	double	text_pos;
	int		r_first_point;
	int		r_last_point;
	int		r_line_len;
	int		txt_x;
	int		txt_y;
	char	*data[4];
	int		bits_per_pixel[4];
	int		line_length[4];
	int		endian[4];
}	t_text;

typedef struct s_map
{
	char	**worldmap;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_ply
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
	double	rotspeed;
	char	direc;
}	t_ply;

typedef struct s_ray
{
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dstc_x;
	double	delta_dstc_y;
	double	side_dstc_x;
	double	side_dstc_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side_hit;
	double	wall_ppclr_dstc;
	int		side;
	double	walldist;
}	t_ray;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		x;
	int		y;
	int		argc;
	char	*no_texture;
	char	**argv;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	int		floor_color_hex;
	int		ceiling_color_hex;
	t_map	map;
	t_ray	ray;
	t_text	textr;
	t_ply	player;
}			t_vars;

typedef struct s_draw_params
{
	int		x;
	int		drawstart;
	int		drawend;
	int		color;
	double	perpwalldist;
	int		lineheight;
	int		texx;
	int		texy;
	int		y;
	double	wallx;
	t_vars	*vars;
}	t_draw_params;

//src/init/game_init.c
void	init_vars(t_vars *vars);

//src/init/init_structur.c
void	init_textur(t_vars *vars);
void	init_colors(t_vars *vars);

//src/parse_config.c
int		parse_config(char *path, t_vars *vars);

//src/debug.c
void	print_texture_paths(t_vars *vars);
void	print_colors(t_vars *vars);
void	print_map(t_vars *vars);

//src/event.c
int		keypress(int keycode, t_vars *vars);
int		keyrelease(int keycode, t_vars *vars);
int		destroy(int keycode, t_vars *vars);
int		motion(int button, int x, int y, t_vars *vars);
int		close_game(t_vars *vars);
void	ft_reset_game(t_vars *vars);

//src/utill.c
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

//src/utils/utils_maps.c
bool	jump_spaces(char ch, int *j, int backwards);

//src/update.c
void	update_player_position(t_vars *vars, int key_pressed);

//src/root_init.c
int		root_init(t_vars *vars);

//src/cub3d.c
void	calculate_fps(t_vars *vars);

//src/free/free.c
void	free_vars(t_vars *vars);
void	ft_free(void *ptr);

//map/map.c
bool	is_map_valid(t_vars *vars);
bool	have_onlyvalid_ch(t_vars *vars);
bool	is_player_valid(t_vars *vars);
bool	is_map_closed(char **map);
bool	is_last_column_closed(char **map);

//map/map1.c
bool	are_all_lines_valid(t_vars *vars);
bool	is_line_horizontal_valid(char *line);
bool	is_line_vertical_valid(char **map);
int		is_line_vertical_valid_aux(int *l, int *ch, int *qt_l, int *qt_ch);
bool	is_first_last_valid(char **map);

bool	is_empty_line(char *line);

//raycasting.c
void	rays_direction(t_vars *vars, int x);
void	delta_dstc(t_vars *vars);
void	step_increment(t_vars *vars);
void	launch_ray(t_vars *vars);
void	draw_floor_ceiling(t_vars *vars);
void	get_wall_height_and_draw(t_vars *vars, int x);
int		raycaster(t_vars *vars);
void	draw_floor_and_ceiling(t_vars *vars);

//move.c
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_player(t_vars *vars, double moveSpeed);
void	rotate_player(t_vars *vars, double rotSpeed);
bool	can_player_move(t_vars *vars, double new_x, double new_y);

//draw.c
void	display_debug_info(t_vars *vars, int key_pressed);
int		draw_frame(t_vars *vars);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	run_cub(t_vars *vars);
void	start_player_position(t_vars *vars);
void	set_plane_positions(t_vars *vars, double plane_x, double plane_y);
void	set_direction_positions(t_vars *vars, double dir_x, double dir_y);
void	get_texture_pointers(t_vars *vars);

//src/parsing/parsing_color.c
void	parse_color(char *color_str, int *color_array);
char	*get_element_info(char *line);
void	get_texture_and_color(t_vars *vars, char **lines);

//src/parsing/parsing_textures.c
bool	is_element_missing(t_vars *vars);
void	convert_color_system(t_vars *vars);
bool	is_rgb_valid(t_vars *vars);
bool	is_spaced(char *str);
bool	is_texture_and_color_valid(t_vars *vars, char **m);

void	make_map_rectangle(t_vars *vars);
bool	is_empty_line(char *line);
int		find_starting_point(char **scene);
void	extract_map(t_vars *vars, char **scene);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_get_pixel(t_text *textr, int x, int y, int index);

void	calculate_and_draw_line(t_draw_params *params);
char	**get_mapfile_info(char *file_path);
bool	is_openble_file(char *path, char *extension, int ext_len);
void	parse_color(char *color_str, int *color_array);
void	skip_whitespace(char *color_str);
void	make_map_rectangle(t_vars *vars);
bool	is_spaced(char *str);
int		close_cub(t_vars *vars);

int		set_texture_index(t_draw_params *params);

void	cleanup(char *fps_str);

#endif
