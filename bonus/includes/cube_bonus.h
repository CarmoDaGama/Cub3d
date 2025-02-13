/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:10:24 by cgama             #+#    #+#             */
/*   Updated: 2025/01/11 10:14:27 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_BONUS_H
# define CUBE_BONUS_H

# include <stdlib.h> 
# include <unistd.h> 
# include <stdio.h> 
# include <string.h>
# include <sys/time.h> 
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>
# include <mlx_int.h>

# include "../libraries/libft/include/libft.h"

# define WIDTH 1920
# define HEIGHT 1040

# define KEY_SPACE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M 109
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_SHIFT 65505

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	int		fd;
	char	**matriz;
	char	*fc_str;
	char	*cc_str;
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	char	plyr_dir;
	double	plyr_x;
	double	plyr_y;
	int		fc_rgb[3];
	int		cc_rgb[3];
	int		fc_hex;
	int		cc_hex;
	int		h;
	int		w;
}	t_map;

typedef struct s_ray
{
	double	plyr_x;
	double	plyr_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dstc_x;
	double	side_dstc_y;
	double	delta_dstc_x;
	double	delta_dstc_y;
	double	wall_ppclr_dstc;
	int		step_x;
	int		step_y;
	int		side_hit;
	double	mov_speed;
}	t_ray;

typedef struct s_minmap
{
	int	m_pressed;
	int	tile_size;
}	t_minmap;

typedef struct s_texture
{
	void	*texture[7];
	int		txt_x;
	int		txt_y;
	int		txt_width[7];
	int		txt_height[7];
	double	text_pos;
	int		r_line_len;
	int		r_first_point;
	int		r_last_point;
	double	wall_hit_pos;
	double	step;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_firearm
{
	t_texture	*t;
	int			move;
	int			fire;
	int			orig_x;
	int			orig_y;
	int			new_x;
	int			new_y;
	int			start_x;
	int			start_y;
	int			scaled_w;
	int			scaled_h;
}	t_firearm;

typedef struct s_game
{
	t_mlx		*mlx;
	t_map		*map;
	t_ray		*ray;
	t_minmap	*mm;
	t_texture	*textr;
	t_firearm	*firearm;
}	t_game;

int		main(int argc, char **argv);
bool	is_argument_valid(t_game *game, int argc, char **argv);

void	free_game(t_game *game, int to_free);
void	free_map(t_map *map);
void	free_mlx(t_mlx *mlx, t_game *game);

int		start_mlx(t_game *game);
int		init_game_struct(t_game *game);
void	get_texture_pointers(t_game *game);
int		init_game_error_handling(t_game *game);

int		parse_file(t_game *game, int argc, char **argv);
char	**get_mapfile_info(t_game *game, char *file_path);
void	replace_tabs_to_space(char **cub);

void	get_texture_and_color(t_game *game, char	**matriz);
char	*get_element_info(char *str);
bool	is_texture_and_color_valid(t_game *game, char **matriz);
bool	is_spaced(char *str);

bool	is_element_missing(t_game *game);
bool	is_rgb_valid(t_game *game);
void	extract_numbers(char *str, int arr[3], int i);
bool	is_color_format_valid(char *str);
void	convert_color_system(t_game *game);

void	extract_map(t_game *game, char **scene);
int		find_starting_point(char **scene);
bool	is_empty_line(char *line);
void	make_map_rectangle(t_game *game);
char	*create_spaced_line(char *line, int big_line);

bool	is_map_valid(t_game *game);
bool	is_player_valid(t_game *game);
bool	have_onlyvalid_ch(t_game *game);
bool	is_map_closed(char	**map);
bool	is_last_column_closed(char **map);

bool	are_all_lines_valid(t_game *game);
bool	is_line_horizontal_valid(char *line);
bool	is_line_vertical_valid(char **map);
int		is_line_vertical_valid_aux(int *l, int *ch, int *qt_l, int *qt_ch);
bool	is_first_last_valid(char **map);

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		my_mlx_get_pixel(t_game *game, int x, int y, int index);
void	draw_floor_ceiling(t_game *game);
void	start_player_position(t_game *game);
void	set_plane_positions(t_game *game, double plane_x, double plane_y);
void	set_direction_positions(t_game *game, double dir_x, double dir_y);

int		raycaster(t_game *game);
void	rays_direction(t_ray *ray, int x);
void	delta_dstc(t_ray *ray);
void	step_increment(t_ray *ray);
void	launch_ray(t_ray *ray, t_map *map);

void	draw_mini_map(t_game *game);
void	render_mini_map(t_game *game, int x, int y);
void	render_mini_map_player(t_game *game);
void	print_map_values(t_game *game);
bool	jump_spaces(char ch, int *j, int backwards);
bool	is_openble_file(char *path, char *extention, int ext_len);

int		close_cub(t_game *game);
int		key_press_handler(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		mouse_handler(int x, int y, t_game *game);
int		mouse_fire(int mousecode, int x, int y, void *param);
void	rotate_left(t_game *game, double speed);
void	rotate_right(t_game *game, double speed);
void	get_wall_height_and_draw(t_game *game, t_ray *ray, int x);
void	draw_texture(t_game *g, int x, int img_index, int txt_h);
void	get_wall_hit_pos(t_game *game);
void	get_render_points(t_game *game);
void	init_firearm_struct(t_game *game);
void	draw_firearm(t_game *game);
void	render_scaled_firearm(t_game *game, int scale_factor, int img_i);
void	render_aim(t_game *game);

#endif
