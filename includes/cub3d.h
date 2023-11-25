/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:15:59 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/25 16:23:44 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/*-------------------------------ERROR DEFINE---------------------------------*/

# define MALLOC_ERROR "An error occured during the memory allocation."
# define MLX_ERROR "An error occured during the mlx fonction."
# define TOO_MUCH_ARG_ERROR "There is too much argument."
# define TOO_FEW_ARG_ERROR "There is too few argument."
# define INCORRECT_FILE_NAME_ERROR "The input file name is incorrect."
# define FILE_NOT_EXIST_ERROR "The input file does not exist."
# define FILE_IS_DIR_ERROR "The input file is a directory."
# define INVALID_ELEMENT "Invalid Element."
# define MAP_OPEN "The current map is open."
# define EMPTY_LINE "There is an empty line in the map."
# define INVALID_CHAR "There is invalid charactere in the map."
# define MUCH_NB_CHAR "There is too much start position"
# define FEW_NB_CHAR "There is too few start position"
# define TEXTURE_TYPE "Texture file type incorrect"
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define WIDTH 1080
# define HEIGHT 720
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
/*---------------------------------STRUCTURE----------------------------------*/

typedef struct s_cord
{
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	end_x;
	unsigned int	end_y;
	unsigned int	lig;
	unsigned int	col;
	char			*path_texture_no;
	char			*path_texture_so;
	char			*path_texture_we;
	char			*path_texture_ea;
	int				**f_colors;
	int				**c_colors;
	char			**ff_rgb;
	char			**cc_rgb;

}					t_cord;

typedef struct s_imag
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_imag;

typedef struct s_engine
{
	void			*mlx;
	void			*win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			ray_dirx;
	double			ray_diry;
	double			plane_x;
	double			plane_y;
	double			delta_distx;
	double			delta_disty;
	double			side_distx;
	double			side_disty;
	double			perp_wall_dist;
	double			wall_x;
	double			move_speed;
	double			rot_speed;
	int				map_x;
	int				map_y;
	int				side;
	int				tex_x;
	int				tex_width;
	int				tex_height;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				**textures;
	char			**c_rgb;
	char			**f_rgb;
	int				buf[HEIGHT + 1][WIDTH + 1];
	int				re_buf;
	t_cord			*cord;
	t_imag			img;

}					t_engine;

typedef struct s_data
{
	char			**map;
	char			**map_path;
	char			**map_game;
	char			**file;
	char			*no;
	char			*we;
	char			*so;
	char			*ea;
	char			*f;
	char			*c;
	int				rgb_c;
	int				rgb_f;
	int				x;
	int				y;
	int				fd;
	int				nb_column;
	int				pos_map;
	t_list			**garb_coll;
	t_cord			cord;
	t_engine		*engine;

}					t_data;

/*------------------------------- GET NEXT LINE-------------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd, t_data *list);
char				*ft_strjoin(char *s1, char *s2, t_data *list);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(const char *s, t_data *data);

/*---------------------------------PARSING----------------------------------*/
int					get_file(t_data *data);
void				get_line(char *line, t_data *data, int *i);
int					get_element(char **file, t_data *data);
int					get_and_check_element(t_data *data);
int					get_and_check_map(t_data *data);
int					get_map(t_data *data);
int					flood_recursively_to_border(char **map, int x, int y);
char				**create_copie(char **map, t_data *data);
int					path_finding(char **map, t_data *data);
int					fill_map(char **map, t_data *data);
char				**get_map_path(char **map, int len, t_data *data);
int					get_len(char **map);
char				**get_map_game(char **map);
void				get_element2(int *flag, char **file, int *i, t_data *data);
void				get_element3(int *flag, char **file, int *i, t_data *data);
int					get_element4(int *flag, char **file, int *i, t_data *data);

// CHECK //
void				check(char *file, int ac, t_data *data);
int					check_file_name(char *file);
int					check_nb_arg(int ac);
int					check_file_exist(char *file, t_data *data);
int					check_is_directory(char *file);
int					check_no(t_data *data);
int					check_we(t_data *data);
int					check_so(t_data *data);
int					check_ea(t_data *data);
int					check_virg(char *f, t_data *data);
int					check_f(t_data *data);
int					check_c(t_data *data);
char				**check_alpha_rgb_c(t_data *data);
char				**check_alpha_rgb_f(t_data *data);
int					check_borders(char **map, t_data *data);
int					check_borders_suite(char **map, t_data *data);
int					check_borders_suite2(char **map, t_data *data);
int					check_empty_line(char **map, t_data *data);
int					check_valid_char(char **map, t_data *data);
int					check_start(char **map, t_data *data);

// ERROR //
void				print_error(char *msg);
void				quit_error(char *msg, t_list **garb_coll);
void				quit_error_no_free(char *msg);

/*---------------------------------EXEC----------------------------------*/

int					exec(t_data *data);
int					get_player_pos(char **map, t_data *data);
int					set_images(t_data *data);
int					key_press(int key, t_data **data);
int					key_press_move_camera_right(int key, t_data **data);
int					key_press_move_camera_left(int key, t_data **data);
void				draw(t_data *data);
int					get_num_tex(t_data *data);
void				draw_utils(t_data *data, int step_x, int step_y);
void				init_dda(t_data *data, int *step_x, int *step_y);
void				init_dda_2(t_data *data, int *step_y);
void				dda(t_data *data, int step_x, int step_y);
void				calcul(t_data **data);
void				draw_color_texture(t_data *data, int x, int tex_num,
						double step);
void				draw_color_texture_utils(t_data **data, double tex_pos,
						double step, int tex_num);
int					init_engine(t_engine *engine);
int					main_loop(t_data **data);
void				up(t_data **data);
void				down(t_data **data);
void				left(t_data **data);
void				right(t_data **data);
int					set_main_img(t_data *data);
int					load_image(t_data *data, int *texture, char *path,
						t_imag *img);
int					malloc_texture2(t_data *data);
int					malloc_textures(t_data *data);
void				draw_utils2(t_data *data);

/*---------------------------------LEAK----------------------------------*/

void				*ft_malloc(unsigned int size, t_list **garb_coll);
void				clear(t_data data);
void				ft_destroy_mlx(t_data *data);
void				ft_destroy(t_data *data);
void				*ft_calloc(size_t nmemb, size_t size, t_data *data);
#endif
